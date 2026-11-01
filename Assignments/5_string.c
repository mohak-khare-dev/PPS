#include <stdio.h>
#include <string.h>
int is_invalid(int *x){
    char catcher;
    if (scanf("%d", x) != 1){return 1;}
    else{
        scanf("%c", &catcher);
        if (catcher != '\n'){
            return 1;
        }else{return 0;}
    }
}
int main(){
    int fun;
    printf("Please choose a string function to execute:\n1 - len\n2 - cpy\n3 - cat\n4 - cmp\n");
    if (is_invalid(&fun)){
        printf("Invalid Input!");
        return 0;
    }
    switch (fun){
        case 1:{
            char s[100];
            int l;
            printf("Enter a string to find its length:\n");
            scanf("%99[^\n]", s);
            l = strlen(s);
            printf("Your string is %d characters long.\n", l);
            break;
        }
        case 2:{
            char src[100], dest[100];
            printf("Please enter the string you would like copied:\n");
            scanf("%99[^\n]", src);
            printf("Address of first character of entered string in memory: %p\n", (void*)src);
            strcpy(dest, src);
            printf("The copied string is:\n%s\n", dest);
            printf("Address of the first character of the copied string in memory: %p\n", (void*)dest);
            break;
        }
        case 3:{
            char src[100], dest[200];
            printf("Please enter the first half of the string you would like concatenated:\n");
            scanf("%99[^\n]", src);
            printf("Please enter the second half of the string you would like concatenated:\n");
            scanf("\n%99[^\n]", dest);
            strcat(src, dest);
            printf("The concatenated string is:\n%s\n", dest);
            break;
        }
        case 4:{
            char str1[100], str2[100];
            int result;
            printf("Please enter the string you would like to compare:\n");
            scanf("%99[^\n]", str1);
            printf("Please enter the string you would like to compare it to:\n");
            scanf("\n%99[^\n]", str2);
            result = strcmp(str1, str2);
            if (result > 0){printf("The first string would appear later than the second one in the dictionary.\n");}
            else if (result < 0){printf("The first string would appear before the second string in the dictionary.\n");}
            else {printf("Both strings are identical to one another.\n");}
            break;
        }
        default:
            printf("Invalid Input!\n");
            break;
    }
    return 0;
}