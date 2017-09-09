#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int total = 256;
    
    int len = strlen(s);
    int max_len = 0;
    int cur_len = 0;
    int prev_index;
    int *visited = (int*)malloc(sizeof(int)*total);
    
    for(int i = 0;i<total;i++)
    {
        visited[i]=-1;
    }
    if(s[0]!='\0')
    {
        visited[s[0]] = 0;
        max_len++;
        cur_len++;
    }
    for(int j = 1;j<len;j++)
    {
        prev_index = visited[s[j]];
        
        if (prev_index == -1 || j- cur_len >prev_index)
            cur_len++;
        else
        {
            if(cur_len > max_len)
                max_len = cur_len;
            
            cur_len = j - prev_index;
        }
        visited[s[j]] = j;
    }
    if(cur_len>max_len)
        max_len = cur_len;
    
    return max_len;
}

int main()
{
    char str[] = "ABDEFGABEF";
    printf("The input string is %s \n", str);
    int len =  lengthOfLongestSubstring(str);
    printf("The length of the longest non-repeating "
           "character substring is %d\n", len);
    return 0;
}