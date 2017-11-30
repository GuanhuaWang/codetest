
#include <stdio.h>
#include <stdlib.h>


int quickSelect(int* nums, int k, int left, int right){
    

    int pivot = nums[(left + right)/2];
    
    int orgL = left, orgR = right;
    printf("===================This is a iteration===============\n");
    printf("orgL is %d, orgR is %d\n", orgL, orgR);
    while(left<=right) {
        while(nums[left]>pivot){
            left ++;
        }
        printf("left is %d\n", left);
        while(nums[right]<pivot){
            right --;
        }
        printf("right is %d\n", right);
        if(left <= right){
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left ++;
            right --;
        }
    }
    if(orgL < right && k <= right) return quickSelect(nums, k, orgL, right);
    if(left < orgR && k >= left) return quickSelect(nums, k, left, orgR);
    
    return nums[k];
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums,k-1,0,numsSize-1);   
}


int main(int argc, char const *argv[])
{
    const int size = 6;
    int arr[size]={3,2,1,5,6,4};

    int c = findKthLargest(arr, size,2);

    printf("number is %d\n", c);
    return 0;
}