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

int main(){
    int m, n, o;
    float matrix_1[10][10] = {0};
    float matrix_2[10][10] = {0};

    printf("Enter the number of rows for the matrices:\n");
    if(is_invalid_int(&m)){
        printf("Invalid Input!\n");
        return 0;
    }
    printf("Enter the number of columns for the matrices:\n");
    if(is_invalid_int(&n)){
        printf("Invalid Input!\n");
        return 0;
    }
    if(m == 0 && n == 0){
        printf("Empty matrices cannot be involved in any operations!\n");
        return 0;
    }

    printf("Enter the elements for the first matrix, one by one:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(is_invalid_float(&matrix_1[i][j])){
                printf("Invalid input!\n");
                return 0;
            }
        }
    }
    printf("Enter the elements for the second matrix, one by one:\n");
    for(int k = 0; k < m; k++){
        for(int l = 0; l < n; l++){
            if(is_invalid_float(&matrix_2[k][l])){
                printf("Invalid input!\n");
                return 0;
            }
        }
    }

    printf("Enter 1 to add the matrices\nEnter 2 to subtract the matrices\n");
    if (is_invalid_int(&o)){
        printf("Invalid Input!");
        return 0;
    }else{
        switch(o){
            case 1:
                for(int a = 0; a < m; a++){
                    for(int b = 0; b < n; b++){
                        printf("%f ", matrix_1[a][b]+matrix_2[a][b]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                for(int p = 0; p < m; p++){
                    for(int q = 0; q < n; q++){
                        printf("%f ", matrix_1[p][q]-matrix_2[p][q]);
                    }
                    printf("\n");
                }
                break;
            default:
                printf("Invalid Input!");
                break;
        }
    }
    return 0;
}