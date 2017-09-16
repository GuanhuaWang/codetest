#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quickSort(int* nums, int first, int last){
    int temp,left,right;
    if(first>=last) return;
    temp = nums[first];
    left = first;
    right = last;
    while(left<right)
    {
        while(left<right && nums[right]>=temp)
            right--;
        if(left<right)
            nums[left]=nums[right];
        while(left<right && nums[left]<=temp)
            left++;
        if(left<right)
            nums[right]=nums[left];
    }
    
    nums[left] = temp;
    quickSort(nums,first,left-1);
    quickSort(nums,left+1,last);
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    int sum,top = -1;
    int begin;
    int end;
    //malloc for C^n_3
    int** final = (int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    
    if(numsSize<3)
    {
        *returnSize =0;
        return final;
    }
    
    quickSort(nums,0,numsSize-1);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
            break;
        if(i>0 && nums[i] ==nums[i-1])
            continue;
        begin = i+1;
        end = numsSize-1;
        while(begin<end)
        {
            sum = nums[i] + nums[begin] + nums[end];
            if(sum == 0){
                top++;
                final[top] = (int*)malloc(sizeof(int)*3);
                final[top][0] = nums[i];
                final[top][1] = nums[begin];
                final[top][2] = nums[end];
                begin++;
                end--;
                while(begin<end && nums[begin] == nums[begin-1])
                    begin++;
                while(begin<end && nums[end] == nums[end+1])
                    end--;
            }
            else if (sum>0) end--;
            else begin++;
        }
    }
    *returnSize = top+1;
    return final;
}

