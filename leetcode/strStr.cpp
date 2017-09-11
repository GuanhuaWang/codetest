#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strStr(char* haystack, char* needle) {

    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if(nlen==0)
        return 0;
    int j = 0;
    int index = 0;
    for(int i =0;i<hlen;i++)
    {
        if(haystack[i]==needle[j])
        {
            if(j == 0)
                index = i;
            j++;
            if(j==nlen)
                return index;
        }
        else
            j=0;
        printf("i is %d, j is %d\n",i, j);
    }
    if(j==nlen) 
        return index;
    else        
        return -1;
}

int main(int argc, char const *argv[])
{
    char c[] = "mississippi";
    char d[] = "issip";
    int f =strStr(c,d);
    printf("f is %d\n",f );
    return 0;
}




//printf("j is %d,index is %d\n", j, index);