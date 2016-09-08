#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sub_string(char *, char *, int);
void sub_string_helper(char *s, char *new) 
{
        int i =0;
        for (i=0;i<strlen(s);i++) 
        {
            sub_string(s, new, i+1);
        }
}
void sub_string(char *s, char *new, int len) 
{
    if (len ==0)
            return; 
    if (*s == '\0') 
            return;
    else 
    {
            *new=*s;
            sub_string(s+1, new+1, len-1);
            printf ("\n %s", new);
    }
}  
#if 0
void sub_string(char *s, char *new, int start, int end, int len) 
{ 
    int i=1;
    if (*s =='\0')
    {
            printf ("\n %s ", new);
            return;
    }
    if (len==1)
    {
            printf ("\n %s ", new);
            return;
    }
    for (i=1;i<len;i++)
    {
            new[start]=s[i];
            sub_string(s+1, new,start+1, end, i);
    }

} 
#endif
int main() 
{
        char *s="abcd";
        char new[100]={0};
//        sub_string(s, new,0, strlen(s)-1, strlen(s));
       //sub_string_helper(s, new);
       sub_string_v2(new,s);
}
