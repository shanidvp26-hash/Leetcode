char* reverseWords(char* s) {
    int left=0,right=0;

    while(s[right]!='\0')
    {
        while(s[right]!=' ' && s[right]!='\0')
        right++;

        int i=left,j=right-1;
        while(i<j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }

        if(s[right] ==' ')
        right++;
        left=right;
    }
    return s;
}