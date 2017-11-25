#include <stdio.h>
#include <stdlib.h>

int arrangeCoins(int n) {

    if(n == 0)
        return 0;
    
    int i = 1;
    int temp = n;
    while(temp >=0)
    {
        temp -=i;
        i++;
        printf("temp is %d, i is %d\n", temp, i);
    }
    
    return i-2;
}

int main(int argc, char const *argv[])
{
    int n = 6;

    int c = arrangeCoins(n);

    printf("%d\n", c);
    return 0;
}