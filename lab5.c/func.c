
#include <stdio.h>
#include <stdlib.h>

double** calc(int n, double **arr1, double **arr2, char c){
    double **arr;
    
    arr = (double**)malloc(n*sizeof(double*));
    for (int i = 0; i<n; i++) arr[i] = (double*)malloc(n*sizeof(double));
    
    if (c == '+'){
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                arr[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
    }    
    
    if (c == '-'){
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                arr[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
    }    
    
    if (c == '*'){
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                arr[i][j] = 0;
                for (int k = 0; k<n; k++){
                    arr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }    
    
    return arr;
}
