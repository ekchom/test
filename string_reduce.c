#if 0 
Shil has a string, , consisting of  lowercase English letters. In one operation, he can delete any pair of adjacent letters with same value. For example, string "" would become either "" or "" after  operation.

Shil wants to reduce  as much as possible. To do this, he will repeat the above operation as many times as it can be performed. Help Shil out by finding and printing s non-reducible form!

Note: If the final string is empty, print .

Input Format

A single string, .

Constraints

Output Format

If the final string is empty, print ; otherwise, print the final non-reducible string.

Sample Input 0

aaabccddd
Sample Output 0

abd
Sample Input 1

baab
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int string_reduce (char *string) ;
#define MAX 100
#define SPECIAL_CHAR '$'
int main() 
{  
        printf ("\n Enter Ctrl+C to exit \n");
        while (1) 
        {
                char string[MAX+1]={0};
                printf ("\nEnter String ");
                scanf("%s", string);
                printf ("\nInput %s\n", string);
                string_reduce (string) ;
                if (string_reduce(string))
                {
                        printf ("\n %s ", string);
                }
                else 
                        printf ("\n Empty String");
        }
}  
int matching_char_position(char *string, char c, int i) 
{
    if (i>=strlen(string))
            return -1;
    
    while (i<strlen(string))
    {
        if ((string[i] != c) && (string[i]!= SPECIAL_CHAR)) 
                return -1;
        else if (string[i] == c) 
                return i;
        i++;

    } 
    return -1;
} 
int compress_string(char *string) 
{
    char *iter=string;
    int i=0, j=0;
    while (i<strlen(string)) 
    {
            if (string[i] != SPECIAL_CHAR) 
            {
                    iter[j]=string[i];
                    j++;
            }
            i++;
    }
    iter[j]='\0';
    return j;
}
int string_reduce (char *string) 
{
    char *iter=string;
    int i =0, j=0;
    int found =1;
    while (found == 1)  
    { 
            found =0;
            iter = string;
            i=0;
            while (i <strlen(string)) 
            {
                char c = iter[i];
                if (c != SPECIAL_CHAR) 
                {
                        int j = matching_char_position(string, c, i+1);
                        if (j != -1)
                        {
                            iter[i]=iter[j]=SPECIAL_CHAR;
                            found = 1;
                            i=j+1;
                        } 
                        else 
                                i++;
                } 
                else 
                        i++;
            } 
    } 
    return compress_string(string);
} 
#if 0
void string_reduce (char *string) 
{
        int i,j,iter;
        int found=1;
        while (found ==  1)
        {
                found =0;
                iter=0;
                while (iter<strlen(string))

                {
                    i = iter;
                    j=i+1;
                    if ((string[i] == string[j]) && (string[i] != SPECIAL_CHAR)) 
                    {
                            string[i]=string[j]=SPECIAL_CHAR;
                            iter=j+1;
                            found =1;
                    } 
                    else 
                    {
                            iter++;
                    }
                }
                i=0;
                iter=0;
                while (i<strlen(string))
                {
                        if (string[i] == SPECIAL_CHAR) 
                        {
                                j=i+1;
                                while ((string[j] == SPECIAL_CHAR) && (j<strlen(string)))
                                        j++;
                                if (j<strlen(string))
                                {
                                    string[iter]=string[j]; 
                                    i=j+1;
                                    iter++;
                                } 
                                else 
                                       i++; 
                        }
                        else  {
                                iter++;
                                i++;
                        }
                }
        }
        string[iter]='\0';
} 
#endif


