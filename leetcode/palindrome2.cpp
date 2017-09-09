#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPalindrome(int x) {
    int leng = 0;
    
    int temp = x;
    while((temp/10)>0)
    {
        leng++;
        temp/=10;
    }
        
    int temp2 = x;
    
    if(x<0) return false;

    for(int i =0;i<(leng+1)/2;i++)
    {
        //printf("i is %d, leng-i is %d\n",array[i],array[leng-i]);
        int left = (int)temp2/pow(10,leng-i);
        int right = (int)fmod(temp2,pow(10,i+1))/pow(10,i);
        printf("left is %d,right is %d\n", left,right);
        printf("gewei is %d, top is %d\n", (int)fmod(temp2,pow(10,i+1)),(int)(right*pow(10,leng-i)));
        temp2 = temp2 - (int)fmod(temp2,pow(10,i+1))-(int)(right*pow(10,leng-i));
        if(left!=right) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int x= 1331;
    if(isPalindrome(x)) 
        printf("It is palidrome\n");
    else 
        printf("It is not palidrome\n" );
    return 0;
}