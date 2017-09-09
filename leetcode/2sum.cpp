#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    static int final[2]={-1,-1};
    for(int i=0;i<numsSize;i++)
    {
        for(int j=0;j<numsSize;j++)
        {
            if(i!=j)
            {
                int curSum = nums[i] + nums[j];
                if(curSum == target)
                {
                    final[0] = i;
                    final[1] = j;
                    break;
                }
            }
        }
        if(final[0] != -1 && final[1] != -1)
            break;
    }
    return final;
}

int main(int argc, char const *argv[])
{
    const int numsSize = 4;
    int mynums[numsSize] = {2,5,5,11};
    int* nums = mynums;
    int target = 10;

    int* cc = twoSum(nums,numsSize,target);
    printf("data is [%d, %d]\n", cc[0],cc[1]);
    return 0;
}