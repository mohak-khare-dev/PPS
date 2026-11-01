#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    if ((n%2) != 0){
        for (int i = n; i >= ((n+1)/2); i--){
            if (i == n){
                for (int j = 0; j < n; j++){
                    printf("-");
                }
                printf("\n");
            }else if (i >= (n - ((n+1)/2))){
                for (int k = 0; k < (n - i); k++){
                    printf(" ");
                }
                for (int a = 0; a < (n - (2*(n-i))); a++){
                    printf("-");
                }
                printf("\n");
            }
        }
        for (int i = 3; i <= n; i += 2){
            for (int c = 0; c < ((n-i)/2); c++){
                printf(" ");
            }
            for (int d = 0; d < i; d++){
                printf("-");
            }
            printf("\n");
        }
    }else{printf("Odd numbers only!\n"); return 0;}
    return 0;
}