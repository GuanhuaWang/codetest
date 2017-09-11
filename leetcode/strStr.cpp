#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strStr(char* haystack, char* needle) {

    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if(nlen==0 || strcmp(haystack, needle) == 0 )
        return 0;
    int index =0;
    
    for(int i =0;i<hlen;i++)
    {
        index = i;
        int flag = 1;
        if(haystack[i]==needle[0])
        {
            for(int k = 1;k<nlen;k++)
            {
             //   printf("haystack[i+k] is %c, needle[i+k] is %c\n",haystack[i+k],needle[k]);
                if(haystack[i+k]!=needle[k])
                {
                    index =0;
                    flag =0;
               //     printf("This is over\n" );
                    break;
                }
            }
        if(flag==1 && i!=hlen-1)
        {
            return index;
            break;
        }

        }
    }
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