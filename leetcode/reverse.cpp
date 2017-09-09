#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int reverse(int x) {
    int temp;
    bool neg=0;
    if(x<=INT_MIN) return 0;
    
    if (x>0)
        temp = x;
    else
    {
        neg = 1;
        temp = -x;
    }
    
    int leng = 1;
    
    int temp2 = temp;
    while((temp2/10)>0)
    {
        leng++;
        temp2 = temp2/10;
    }
    //printf("length is %d\n", leng);
    //int *final = new int [leng];
  //  int *final = (int*)malloc(leng*sizeof(int));
    long long int finalResult = 0;
    
    for(int i =0;i<leng;i++)
    {
        int digit = temp%10;
     //   final[leng-i] = digit;
        finalResult += digit*pow(10,leng-i-1);
        //finalResult = finalResult*10 + digit;
        if(temp>=10)
            temp = temp/10;
        else
            temp = temp%10;

        //printf("iteration is %d,the digit is %d,final[leng-i] is %d,finalResult is %d\n", i,digit,final[leng-i],finalResult);
    }

    if(finalResult >=INT_MAX) return 0;
    
    if(neg==1)
        return -finalResult;
    else
        return finalResult;
}

int main(int argc, char const *argv[])
{
    int x = 10;
    int c = reverse(x);
    printf("Number is %d, reversed is %d\n", x,c);
    return 0;
}