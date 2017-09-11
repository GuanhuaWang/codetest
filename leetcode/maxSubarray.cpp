#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize) {
    int curSum=nums[0];
    int max=nums[0];
    for(int i =0;i<numsSize;i++)
    {
        printf("=========i is %d===========\n",i);
        curSum = nums[i];
        if(curSum>max)
            max = curSum;
        printf("nums[i] is %d\n",nums[i]);
        for(int j=i+1;j<numsSize;j++)
        {        
            printf("====j is %d====\n",j);
            curSum+=nums[j];
            printf("curSum is %d\n",curSum);
            if(max<curSum)
            max = curSum;
        }
        curSum = 0;
    }
    
    return max;
}

int main(int argc, char const *argv[])
{
    int c[]={-2,-4};
    int final = maxSubArray(c,2);
    printf("data is %d\n", final);
    return 0;
}