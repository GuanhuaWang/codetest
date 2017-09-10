#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int temp;
    int j = 0;
    if(numsSize ==0) return 0;
    
    for(int i =1;i<numsSize;i++)
    {
        if(nums[j]!=nums[i])
            nums[++j]=nums[i];   
    }
    return j+1;
}

int main(int argc, char const *argv[])
{
    int nums[] = {0,0,0,1,2,4,4};
    int size = 7;

    int final = removeDuplicates(nums,size);
    for(int i = 0;i<final;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}