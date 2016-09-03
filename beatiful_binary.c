#if 0 
Alice has a binary string of length . She thinks a binary string is beautiful if and only if it doesnt contain the substring .

In one step, Alice can change a  to a  (or vice-versa). Count and print the minimum number of steps needed to make Alice see the string as beautiful.

Input Format

The first line contains an integer,  (the length of binary string ). 
The second line contains a single binary string, , of length .

Constraints

Each character in .
Output Format

Print the minimum number of steps needed to make the string beautiful.

Sample Input 0

7
0101010
Sample Output 0

2
#endif 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define ZERO '0'
#define ONE '1'
#define PATTERN "010"
int my_string_compare(char *iter, char *pattern) 
{
    if (strlen(iter) >= strlen(pattern)) 
    {
        return strncmp(iter, pattern, strlen(pattern));
    } 
    else 
            return 1;

}
int main(){
    int n; 
    int i,count=0;
    char *iter;
    scanf("%d",&n);
    char* B = (char *)malloc(10240 * sizeof(char));
    scanf("%s",B);
    i=0;
    iter=B;
    while (i<n) 
    {
        if (my_string_compare(&iter[i], PATTERN)==0) 
        {
            iter[i+2] = ONE;
            count++;
            i=i+2;
        }
        else 
                i++;
    }
    printf ("\n%d", count);
    return 0;
}

