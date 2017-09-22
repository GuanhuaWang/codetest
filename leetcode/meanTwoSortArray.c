#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int count1=0;
    int count2=0;

    if(nums1Size == 0 && nums2Size ==0)
        return 0;
    else if(nums1Size==0 && nums2Size !=0)
    {
        if(nums2Size%2==0)
            return (nums2[(int)(nums2Size/2-1)]+nums2[(int)(nums2Size/2)])/2.0;
        else
            return nums2[(int)(nums2Size/2)];
    }
    else if(nums1Size != 0 && nums2Size ==0)
    {
        if(nums1Size%2==0)
            return (nums1[(int)(nums1Size/2-1)]+nums1[(int)(nums1Size/2)])/2.0;
        else
            return nums1[(int)(nums1Size/2)];
    }
    else if(nums1Size == 1 && nums2Size ==1 && nums1[0] == nums2[0])
    {
        return nums1[0];
    }


    for(int i = 0;i<nums1Size;i++)
    {
        for(int j = 0; j<nums2Size;j++)
        {
            //printf("count1 is %d, count2 is %d\n", count1,count2);
            if(nums2[j]>=nums1[i])
                count1++;
            else
                count2++;
            
            if(nums1Size+nums2Size==3 && count1+count2==1)
            {
                if(count1>count2)
                    return nums2[0];
                else 
                    return nums1[0];
            }
            else if(count1+count2==(nums1Size+nums2Size)/2-1)
            {   
                //printf("count1 is %d, count2 is %d\n", count1,count2);
                break;
            }
        }
        if(count1+count2==(nums1Size+nums2Size)/2-1)
            break;
    }
   // printf("count1 is %d, count2 is %d\n", count1,count2);
   // printf("data is %d, %d \n",nums1[count1],nums2[count2-1]);
    return (nums1[count1]+nums2[count2])/2.0;
}

int main(int argc, char const *argv[])
{
    
    int a1[] = {};
    int a2[] ={1,2,3,4,5};

    double c = findMedianSortedArrays(a1,0,a2,5);
    printf("the mean is %f\n", c);
    return 0;
}