#if 0 
andy likes palindromes. A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as it does forward. For example, madam is a palindrome.

On her  birthday, Sandys uncle, Richie Rich, offered her an -digit check which she refused because the number was not a palindrome. Richie then challenged Sandy to make the number palindromic by changing no more than digits. Sandy can only change  digit at a time, and cannot add digits to (or remove digits from) the number.

Given  and an -digit number, help Sandy determine the largest possible number she can make by changing digits.

Note: Treat the integers as numeric strings. Leading zeros are permitted and cant be ignored (So 0011 is not a palindrome, 0110 is a valid palindrome). A digit can be modified more than once.

Input Format

The first line contains two space-separated integers,  (the number of digits in the number) and  (the maximum number of digits that can be altered), respectively. 
The second line contains an -digit string of numbers that Sandy must attempt to make palindromic.

Constraints

Each character  in the number is an integer where .
Output Format

Print a single line with the largest number that can be made by changing no more than  digits; if this is not possible, print -1.

Sample Input 0

4 1
3943
Sample Output 0

3993
Sample Input 1

6 3
092282
Sample Output 1

992299
Sample Input 2

4 1
0011
Sample Output 2

-1
#endif
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    char* number = (char *)malloc(102400 * sizeof(char));
    char *iter=number, *mid, *fh, *sh;
    unsigned int change[102400]={0};
    int j, i, palin=1;
    scanf("%d %d",&n,&k);
    scanf("%s",number); 
    j=k;
    i=n/2 -1; 
    j=n/2;
    if (n%2) 
            j=j+1;
    while (k && (i>=0) && (j<n))
    {
 
        sh = &(number[j]);
        fh = &(number[i]);
        if (*sh != *fh) 
        {

            (*sh > *fh) ?(*fh = *sh) :(*sh = *fh);
            change[fh-number] = change[sh-number]=1;
            k--;
        } 
        j++;
        i--;
    } 
    if (k) 
    {
        i= 0;
        j= n-1;
        while (i<j && k) 
        {
            if (change[i] && (number[i]!='9'))
            {
                number[i]='9';
                number[j]='9';
                k--;
            } 
            else if ((k >=2) && (number[i]!='9'))
            {
                number[i]='9';
                number[j]='9';
                k--;
                k--;
            } 
             
            i++;
            j--;
        } 
        if ((i==j) && k)
        {
                number[i]='9';
        }

    } 
    
    fh = number;
    sh = number+n-1; 
    while (fh <= sh) 
    {
        if (*fh != *sh)
        {
            palin=0;
            break;
        }
        fh++;
        sh--;
    } 
    if (palin) 
    {
            printf ("%s\n", number);
    }
    else 
            printf ("-1\n");
    free(number);
    return 0;
}

