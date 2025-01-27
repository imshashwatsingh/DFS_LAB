#include<stdio.h>
#include<stdbool.h>

bool isSparseMatrix(int rows,int cols,int arr[][10]){
    int count = 0;
    int nums[rows*cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(arr[i][j] == 0){
                count++;
            }else{
                printf("%d ",arr[i][j]);
                nums[i] = arr[i][j];
            }
        }
    }
    return count >= (rows*cols)/2;
    
}

int main(){
    int arr[10][10] = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    bool result = isSparseMatrix(arr,10,10);
    printf("\n isSparseResult =  %d",result);
    
}