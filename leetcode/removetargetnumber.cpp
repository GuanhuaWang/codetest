#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int final = numsSize;
    int count = 10;
    for(int i =0;i<numsSize;)
    {
        if(nums[i]==val)
        {
            final--;
            for(int j = i;j<final;j++)
            {
                nums[j] = nums[j+1];
            }
        }
        else
            i++;
/*
      printf("=======i is %d======\n",i);

            for(int i = 0;i<numsSize;i++)
            {
                printf("%d ",nums[i]);
            }
            printf("\n");*/

        if(final ==i)break;

    }
    return final;
}

int main(int argc, char const *argv[])
{
    int nums[] = {3,2,3,3,2,3};
    int size = 6;

    int final = removeElement(nums,size,3);
    printf("==========final===========\n");
    for(int i = 0;i<final;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}