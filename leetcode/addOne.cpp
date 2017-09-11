#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *temp = (int*)malloc(digitsSize*sizeof(int));
    int carry = 1;
    int cur = 0;
    for(int i =digitsSize-1;i>=0;i--)
    {
        carry += digits[i];
        cur = carry%10;
        carry/=10;
        temp[i]= cur;
    }
        
    if(carry==1)
    {
        returnSize[0]=1;
        for(int j =0;j<digitsSize;j++)
            returnSize[j+1]=temp[j];
        printf("aaa\n");
        return returnSize;
    }
    else
    {
        for(int j =0;j<digitsSize;j++)
            returnSize[j]=temp[j];
        printf("bbb\n");
        return returnSize;
    }
    

}

int main(int argc, char const *argv[])
{
    int a[] = {9,9};
    int c[] = {0,0,0};
    int*b =plusOne(a,2,c);
    for(int i =0;i<3;i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}