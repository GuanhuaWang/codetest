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
    
    int* array = (int*)malloc(sizeof(int)*leng);
    int temp2 = x;
    int prev = 0;
    for(int i = 0; i<leng+1;i++)
    {
        array[i] = (int)(temp2/pow(10,leng-i));
        printf("array[%d] is %d\n",i,array[i]);
        temp2 = (int) (fmod(temp2,pow(10,leng-i)));
    }

    for(int i =0;i<leng;i++)
    {
        //printf("i is %d, leng-i is %d\n",array[i],array[leng-i]);

        if(array[leng-i]!=array[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int x= 1231;
    if(isPalindrome(x)) 
        printf("It is palidrome\n");
    else 
        printf("It is not palidrome\n" );
    return 0;
}