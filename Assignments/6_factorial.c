#include <stdio.h>
int rec(int num){
    if (num == 0 || num == 1){
        return 1;
    }else{
        return num * rec(num-1);
    }
}

int nrec(int num){
    int result = num;
    for (int i = 1; i < num; i++){
        result *= num - i;
    }
    if (num == 0){return 1;}
    else {return result;}
}

int is_invalid(int *x);

int main(void){
    int num;
    printf("Please enter a number up to 12 of which you would like to find the factorial:\n");
    if (is_invalid(&num)){
        printf("Invalid Input!\n");
        return 0;
    }
    printf("The factorial of your chosen number, using a recursive function:\n%d\nusing a non-recursive function:\n%d\n", rec(num), nrec(num));
    return 0;
}

int is_invalid(int *x){
    if (scanf("%d", x) != 1 || *x < 0 || *x > 12){return 1;}
    else{
        char catcher;
        scanf("%c", &catcher);
        if (catcher != '\n'){
            return 1;
        }else{return 0;}
    }
}