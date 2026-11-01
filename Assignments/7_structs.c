#include <stdio.h>

int is_invalid_float(float *x){
    char catcher;
    if (scanf("%f", x) != 1){return 1;}
    else{
        scanf("%c", &catcher);
        if (catcher != '\n'){
            return 1;
        }else{return 0;}
    }
}
int is_invalid_int(int *x){
    char catcher;
    if (scanf("%d", x) != 1){return 1;}
    else{
        scanf("%c", &catcher);
        if (catcher != '\n'){
            return 1;
        }else{return 0;}
    }
}

int main(void){
    typedef struct {
       char name[100];
       int roll_number;
       float Subject1;
       float Subject2;
       float Subject3;
    } Student;
    Student details[100];
    int roll_numbers[100];
    int strength;
    int chosen_rno;
    printf("Enter the number of students:\n");
    if(is_invalid_int(&strength)){
        printf("Invalid Input!\n");
        return 0;
    }
    printf("Enter the details for each student:\n");
    for (int i = 0; i < strength; i++){
        printf("Student %d:\n", (i+1));
        printf("Name:\n");
        scanf("%s", &details[i].name);
        printf("PRN:\n");
        if(is_invalid_int(&details[i].roll_number)){
            printf("Invalid Input!\n");
            return 0;
        }
        for (int k = 0; k < i; k++){
            if (details[i].roll_number == roll_numbers[k]){
                printf("Cannot use same PRN for multiple entries!\n");
                return 0;
            }
        }
        printf("Marks:\n");
        if(is_invalid_float(&details[i].Subject1)){
            printf("Invalid Input!\n");
            return 0;
        }

        if(is_invalid_float(&details[i].Subject2)){
            printf("Invalid Input!\n");
            return 0;
        }

        if(is_invalid_float(&details[i].Subject3)){
            printf("Invalid Input!\n");
            return 0;
        }
    }
    printf("Enter the PRN of the student whose result you'd like to access:\n");
    scanf("%d", &chosen_rno);
    for (int j = 0; j < strength; j++){
        if(details[j].roll_number == chosen_rno){
            printf("%10s %10s %10s %10s %10s %10s %10s\n", "Roll No.", "Name", "Subject 1", "Subject 2", "Subject 3", "Total", "Percentage");
            printf("%10d %10s %10.1f %10.1f %10.1f %10f %10.2f", details[j].roll_number, details[j].name, details[j].Subject1, details[j].Subject2, details[j].Subject3, (details[j].Subject1 + details[j].Subject2 + details[j].Subject3), (details[j].Subject1 + details[j].Subject2 + details[j].Subject3)*100/300);
        }else if(j == (strength - 1) && details[j].roll_number != chosen_rno){
            printf("No such student found.\n");
        }
    }
    return 0;
}