#include <stdio.h>
int main(void){
    FILE *src, *dest;
    src = fopen("src", "r");
    dest = fopen("dest", "w+");
    char holder[1000];
    char holder1[1000];
    if (src != NULL){
        while (fgets(holder, 1000, src)){
            fputs(holder, dest);
        }
        fclose(dest);
        fclose(src);
    }else{
        printf("File opening failed.\n");
    }
}