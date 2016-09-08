#if 0
Amanda has a string, , of  lowercase letters that she wants to copy into a new string, . She can perform the following operations any number of times to construct string :

Append a character to the end of string  at a cost of  dollar.
Choose any substring of  and append it to the end of  at no charge.
Given  strings (i.e., ), find and print the minimum cost of copying each  to  on a new line.

Input Format

The first line contains a single integer, , denoting the number of strings. 
Each line  of the  subsequent lines contains a single string, .

Constraints

Subtasks

 for  of the maximum score.
Output Format

For each string  (where ), print the minimum cost of constructing string  on a new line.

Sample Input

2
abcd
abab
Sample Output

4
2
Explanation

Query 0: We start with  and .

Append character  to  at a cost of  dollar, .
Append character  to  at a cost of  dollar, .
Append character  to  at a cost of  dollar, .
Append character  to  at a cost of  dollar, .
Because the total cost of all operations is  dollars, we print  on a new line.

Query 1: We start with  and .

Append character  to  at a cost of  dollar, .
Append character  to  at a cost of  dollar, .
Append substring  to  at no cost, .
Because the total cost of all operations is  dollars, we print  on a new line.

Note

A substring of a string  is another string  that occurs "in"  (Wikipedia). For example, the substrings of the string "" are "", "" ,"", "", "", and "".
#endif
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define LEN (10*10*10*10*10 +1)
#define NUM_CHAR 26 
#define NUM_SIZE (NUM_CHAR+7)/8
#define SET_BIT(map, i) (map[i/8] |= (1<<(i%8)))
#define CHK_BIT(map, i) (map[i/8] & (1<<(i%8))) 
typedef unsigned int bitmap[NUM_SIZE];
int cost_for_substring(char *s, char *d) 
{
    bitmap b={0};
    int i=0;
    char c;
    int count=0;
    while ((c=*(s+i)) !='\0') 
    {
        int n = c-'a';
        if (CHK_BIT(b, n))
                ;
        else 
        {
                SET_BIT(b, n);
                count++;
        }
        i++;
    }
    return count;

}
int main(){
    int n,a0,i; 
    int *cost;
    scanf("%d",&n);
    cost = (int *)malloc(n*sizeof(int));
    for(a0 = 0; a0 < n; a0++){
        char* s = (char *)malloc(LEN* sizeof(char));
        char *p = (char *)malloc(LEN*sizeof(char));
        scanf("%s",s);
        cost[a0] = cost_for_substring(s,p);
        free(s);
        free(p);
    } 

    for(a0 = 0; a0 < n; a0++){
            printf ("%d \n" ,cost[a0]);
    }
    free (cost);
    return 0;
}

