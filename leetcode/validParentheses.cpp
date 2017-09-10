#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isValid(char* s) {
    int leng = strlen(s);
    char* stack = (char*)malloc(sizeof(char)*(leng+1));
    
    stack[0]='o';
    int j = 1;
    for(int i =0;i<leng;i++)
    {
        printf("i is %d, j is %d\n",i,j );
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[j]=s[i];
            printf("stack j data is %c\n", stack[j]);
            j++;
            printf("this is j++\n");
        }
        else if (s[i] == ')' && stack[j-1] == '(' || (s[i]==']' && stack[j-1] =='[') || (s[i] == '}' && stack[j-1] =='{'))
        {
            stack[j] ='o';
            j--;
            printf("this is j--\n");
        }
        else
        {
            j++;
            break;
        }
        printf("=======================\n");
    }


    
    if(j==1) 
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    char*s = "()[]{}";
    printf("result is %d\n", isValid(s));
    return 0;
}