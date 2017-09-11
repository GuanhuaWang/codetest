int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count=0;
    int flg =0;
    int blank =0;
    for(int k = 0;k<len;k++)
    {
        if(s[k]==' ')
        {
            blank++;
            flg = 1;
        }
    }
    if(blank==len) return 0;
    if(blank ==1 && s[len-1]==' ') return len-1;
    if(flg==0)
        return len;
    
    for(int i = 0;i<len;i++)
    {
        if(s[i]==' ')
        {
            count=0;
            for(int j =i+1;j<len;j++)
            {
                if(s[j]!=' ')
                    count++;
                else
                {
                    break;    
                }
            }
        }
    }
    if(len==0)
        return 0;
    else
        return count;
}