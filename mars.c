#if 0 
Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string, , determine how many letters of Samis SOS have been changed by radiation.

Input Format

There is one line of input: a single string, .

Note: As the original message is just SOS repeated  times, s length will be a multiple of .

Constraints

 will contain only uppercase English letters.
Output Format

Print the number of letters in Samis message that were altered by cosmic radiation.

Sample Input 0

SOSSPSSQSSOR
Sample Output 0

3
Sample Input 1

SOSSOT
Sample Output 1

1
#endif
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define SOS "SOS"
int main(){
    char* S = (char *)malloc(10240 * sizeof(char));
    char *iter=S;
    int i=0;
    int count=0;
    scanf("%s",S);
    while (*iter !='\0') 
    {
        char c = SOS[i];
        if (c!=*iter)
                count++;
        i=(i+1)%3;
        iter++;
    }
    printf ("%d\n", count);
    free(S);
    return 0;
}
