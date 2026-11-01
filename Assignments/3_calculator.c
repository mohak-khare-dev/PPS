#include <stdio.h>
int is_invalid(float *x){
    char catcher;
    if (scanf("%f", x) != 1){return 1;}
    else{
        scanf("%c", &catcher);
        if (catcher != '\n'){
            return 1;
        }else{return 0;}
    }
}
int main(){
    float a, b;
    char o, extra;
    printf("Please enter a number:\n");
    if (is_invalid(&a)){
        printf("Invalid input!\n");
        return 0;
    }
    printf("Please enter another number:\n");
    if (is_invalid(&b)){
        printf("Invalid input!\n");
        return 0;
    }
    printf("Please select an operation:\n1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n");
    scanf(" %c", &o);
    scanf("%c", &extra);
    if (extra != '\n'){
        printf("Invalid operator!\n");
        return 0;
    }

    switch(o){
        case '1':
            printf("%f + %f = %f\n", a, b, a+b);
            break;
        case '2':
            printf("%f - %f = %f\n", a, b, a-b);
            break;
        case '3':
            printf("%f x %f = %f\n", a, b, a*b);
            break;
        case '4':
            if (b==0){
                printf("Undefined!\n");
            }else{
            printf("%f/%f = %f\n", a, b, a/b);
            }
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
    return 0;
}