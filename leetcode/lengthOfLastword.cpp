#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) {

    int len = strlen(s);
    if (len == 0) return 0;
    int i = len -1;
    while(s[i] ==' ' && i>=0) i--;
    if(i == -1)
        return 0;
    
    int end = i;
    for(;i>=0;i--)
    {
        if(s[i] == ' ')
            break;
    }
    if(i == -1)
        return end+1;
    return end-i;
}

int main(int argc, char const *argv[])
{
    char c[]={"  aaa     "};
    int a = lengthOfLastWord(c);
    printf("a is %d\n", a);
    return 0;
}