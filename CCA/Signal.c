#include <stdio.h>

#define CHANNELS 3
#define INTERVALS 4
#define INTERVAL_LENGTH 5

int read(FILE *channel, float *signal_strength, char *timestamp){
    char entry[100];
    char exch = 0;
    if (fgets(entry, sizeof(entry), channel) == NULL){
        return 1;
    }
    int matches = sscanf(entry, "%99[^,],%f%c", timestamp, signal_strength, &exch);
    if (exch != '\n' && matches != 2 || timestamp[0] == '\0'){
        return 1;
    }
    return 0;
}

int approx_equal(float a, float b){
    float diff = a - b;
    if (diff < 0){
        diff = -diff;
    }
    return diff < 0.001f;
}

void print_max_interval(float sums[], char timestamps[][100], int intervals){
    if (intervals <= 0) {
        printf("Invalid amount of intervals provided.\n");
        return;
    }
    int all_equal = 1;
    for (int i = 1; i < intervals; i++) {
        if (!approx_equal(sums[i], sums[0])) {
            all_equal = 0;
            break;
        }
    }
    if (all_equal) {
        printf("The combined strength of all intervals is equal (%f).\n", sums[0]);
        return;
    }

    float max_val = sums[0];
    for (int i = 1; i < intervals; i++) {
        if (sums[i] > max_val) {
            max_val = sums[i];
        }
    }

    printf("Maximum combined strength %.2f found at interval(s): ", max_val);
    int first = 1;
    for (int i = 0; i < intervals; i++) {
        if (approx_equal(sums[i], max_val)) {
            if (!first) {
                printf(", ");
            }
            printf("%d (%s)", (i+1), timestamps[i]);
            first = 0;
        }
    }
    printf("\n");
}

int main(){
    float avg[CHANNELS] = {0};
    float sums[INTERVALS] = {0};
    float signal_strength[CHANNELS][INTERVALS];
    char timestamps[INTERVALS][100];
    char skipped_timestamp[100];

    FILE *channel_1 = fopen("channel_1.csv", "r");
    if (channel_1 == NULL){
        printf("Channel 1 log could not be opened!\n");
        return 1;
    }
    for (int i = 0; i < INTERVALS; i++){
        for (int k = 0; k < INTERVAL_LENGTH; k++){
            if (read(channel_1, &signal_strength[0][i], timestamps[i])){
                printf("Channel 1 log contains corrupted data!\n");
                fclose(channel_1);
                return 1;
            }
        }
        avg[0] += (signal_strength[0][i])/INTERVALS;
    }
    fclose(channel_1);

    FILE *channel_2 = fopen("channel_2.csv", "r");
    if (channel_2 == NULL){
        printf("Channel 2 log could not be opened!\n");
        return 1;
    }
    for (int i = 0; i < INTERVALS; i++){
        for (int k = 0; k < INTERVAL_LENGTH; k++){
            if (read(channel_2, &signal_strength[1][i], skipped_timestamp)){
                printf("Channel 2 log contains corrupted data!\n");
                fclose(channel_2);
                return 1;
            }
        }
        avg[1] += (signal_strength[1][i])/INTERVALS;
    }
    fclose(channel_2);

    FILE *channel_3 = fopen("channel_3.csv", "r");
    if (channel_3 == NULL){
        printf("Channel 3 log could not be opened!\n");
        return 1;
    }
    for (int i = 0; i < INTERVALS; i++){
        for (int k = 0; k < INTERVAL_LENGTH; k++){
            if (read(channel_3, &signal_strength[2][i], skipped_timestamp)){
                printf("Channel 3 log contains corrupted data!\n");
                fclose(channel_3);
                return 1;
            }
        }
        avg[2] += (signal_strength[2][i])/INTERVALS;
    }
    fclose(channel_3);

    for (int c = 0; c < CHANNELS; c++){
        printf("Average strength from channel %d: %.2f\n", c + 1, avg[c]);
    }

    for (int i = 0; i < INTERVALS; i++){
        for (int k = 0; k < CHANNELS; k++){
            sums[i] += signal_strength[k][i];
        }
    }

    print_max_interval(sums, timestamps, INTERVALS);
    return 0;
}