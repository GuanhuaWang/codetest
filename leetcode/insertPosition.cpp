#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    if(target<nums[0])
        return 0;
    if(target>nums[numsSize-1])
        return numsSize;
    
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            printf("this is AAA\n");
            return i;
            break;
        }
        else if(nums[i]<target && target<nums[i+1])
        {
            printf("this is BBB\n");
            return i+1;
            break;
        }
    }
    return -100;
    
}

int main(int argc, char const *argv[])
{
    int a[]={1,3};
    int target = 2;
    int c = searchInsert(a,2,2);
    printf("=====%d======\n",c);
    return 0;
}