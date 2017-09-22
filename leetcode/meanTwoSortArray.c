#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if((nums1Size+nums2Size)%2 == 0)
    {
        return (GetMedian(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2)+GetMedian(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1))/2.0;
    }
    else
        return GetMedian(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1);
}

int min(int a, int b){
    if(a>=b)
        return b;
    else
        return a;
}

int GetMedian(int* A, int m, int* B, int n, int k){
    if(m>n)
        return GetMedian(B,n,A,m,k);
    if(m == 0)
        return B[k-1];
    if(k == 1)
        return min(A[0],B[0]);
    int a = min(k/2,m);
    int b = k-a;
    if(A[a-1]<=B[b-1])
        return GetMedian(A+a,m-a,B,n,k-a);
    return GetMedian(A,m,B+b,n-b,k-b);
    
}

int main(int argc, char const *argv[])
{
    
    int a1[] = {};
    int a2[] ={1,2,3,4,5};

    double c = findMedianSortedArrays(a1,0,a2,5);
    printf("the mean is %f\n", c);
    return 0;
}