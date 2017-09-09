#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i;
    int flg=0;
    if(!strs || !strs[0]) return "";
    
    for(i =0; strs[0][i] !='\0';i++)
    {
        for(int j = 0;j<strsSize;j++)
            if(strs[j][i]-strs[0][i]!=0 || strs[j][i]=='\0')
            {
                flg = 1;
                break;
            }
        
        if(flg ==1)break;
    }
    if(i==0) return "";
    char* output=(char*)malloc(i+1);
    for(int k = 0;k<i;k++)
        output[k] = strs[0][k];
    output[i] = '\0';
    
    return output;
}

int main(int argc, char **argv)
{
    char*s[]= {"aba", "ababb", "abc"};
    char * c =longestCommonPrefix(s,3);
    printf("%s\n", c);
    return 0;
}