#if 0
Suppose you have a String, , of length  that is indexed from  to . You also have some String, , that is the reverse of String .  is funny if the condition  is true for every character from  to .

Note: For some String ,  denotes the ASCII value of the  -indexed character in . The absolute value of an integer, , is written as .

Input Format

The first line contains an integer,  (the number of test cases). 
Each line  of the  subsequent lines contain a string, .

Constraints

Output Format

For each String  (where ), print whether it is  or  on a new line.

Sample Input

2
acxz
bcxz
Sample Output

Funny
Not Funny
#endif 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LEN (10000+1)
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))
int main() {

    int num_string,i,j, count=0;
    char (*string)[LEN]; 
    scanf ("%d", &num_string);
    string = malloc(sizeof(*string)*num_string);
    if (!string)
            return 0;
    for (i=0 ; i<num_string;i++) {
            scanf("%s", string[i]);
    } 

    for (i=0 ; i<num_string;i++) {
            int funny = 1;
            char *start= (char *)&string[i]; 
            char *end  = (char *) (&string[i])+strlen(string[i])-1; 
            while (*(start+1) != '\0') 
            {
                char *next = start+1;
                char *back = end-1;
                if (ABS(*next, *start) != ABS(*end, *back))
                {
                        funny =0;
                        break;
                }
                start++;
                end--;
            }
            printf ("%sFunny\n",funny?"":"Not ");
    }
    free(string);
    return 0;
}

