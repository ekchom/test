#if 0 
Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesnt like ABAA. Given a string containing characters  and  only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.

Input Format

The first line contains an integer , i.e. the number of test cases. 
The next  lines contain a string each.

Output Format

For each test case, print the minimum number of deletions required.

Constraints

 
 length of string 

Sample Input

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB
Sample Output

3
4
0
0
4
Explanation

AAAA  A, 3 deletions
BBBBB  B, 4 deletions
ABABABAB  ABABABAB, 0 deletions
BABABA  BABABA, 0 deletions
AAABBB  AB, 4 deletions because to convert it to AB we need to delete 2 As and 2 Bs
#endif
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN (10*10*10*10*10)
int process_string(char *string) 
{
    char *iter = string; 
    int i=0;
    int count=0;
    iter = string+1;
    while (i<strlen(string)) 
    {
        if ((*iter != '\0') && string[i] ==*iter) 
        {
                count++;
                iter++;
        } 
        else  {
                i = (iter - string) ;
                iter++;
        }
    } 
    return count;
}
int main() { 

    int num_string, i;
    char **string;
    scanf("%d", &num_string);
    
    string = (char **)(malloc(sizeof(char *)*num_string));
    if (!string)
            return;
    for (i=0;i<num_string;i++)
    { 
            string[i] = (char *)malloc(sizeof(char*)*MAX_LEN);
            if (string[i]) 
                    scanf ("%s", string[i]);
    }
    for (i=0;i<num_string;i++)
    {
        int num =process_string(string[i]);
        printf ("%d\n", num);
        free(string[i]);
    }
    free(string);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

