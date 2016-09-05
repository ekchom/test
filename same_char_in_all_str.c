#if 0
John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lower-case Latin letter from a to z. An element can be present multiple times in a rock. An element is called a gem-element if it occurs at least once in each of the rocks.

Given the list of  rocks with their compositions, display the number of gem-elements that exist in those rocks.

Input Format

The first line consists of an integer, , the number of rocks. 
Each of the next  lines contains a rocks composition. Each composition consists of lower-case letters of English alphabet.

Constraints 
 
Each composition consists of only lower-case Latin letters (a-z). 
 length of each composition 

Output Format

Print the number of gem-elements that are common in these rocks. If there are none, print 0.

Sample Input

3
abcdde
baccd
eeabg
Sample Output

2
Explanation

Only "a" and "b" are the two kinds of gem-elements, since these are the only characters that occur in every rocks composition.
#endif
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LEN (100+1) 
#define NUM_CHAR 26 
#define LOWERCASE(a) (((a>='A') && (a<='Z')) ?(a-'A'):(((a>='a') &&(a<='z')) ?(a-'a'):0))
#define SETBIT(BITMAP,i) (BITMAP.bits[i/8] |= (1<<(i%8)))
#define CHKBIT(BITMAP,i) (BITMAP.bits[i/8] & (1<<(i%8)))
#define NUMSIZE (NUM_CHAR+7)/8
typedef struct bitmap 
{
        unsigned char bits[NUMSIZE];
} bitmap;
int main() {
    int num_rock,i,j, count=0;
    char (*string)[LEN]; 
    bitmap *bitmaps;
    scanf ("%d", &num_rock);
    string = malloc(sizeof(*string)*num_rock);
    if (!string)
            return 0;
    for (i=0 ; i<num_rock;i++) {
            scanf("%s", string[i]);
    } 
    bitmaps = (bitmap *) malloc(sizeof(bitmap)*num_rock);
    if (!bitmaps)
            return 0;
    
    for (i=0; i<num_rock; i++) 
    {
            char *iter = (char *)&string[i];
            while (*iter != '\0') 
            {
                    SETBIT(bitmaps[i],LOWERCASE(*iter));
                    iter++;
            }
    } 
    for (i=0; i<NUM_CHAR;i++)
    {
        int j=0;
        for (j=0;j<num_rock;j++)
        {
                if (!CHKBIT(bitmaps[j], i))
                        break;
        }
        if (j == num_rock)
                count++;
    } 
    printf ("\n%d", count);
    free(bitmaps);
    free(string);
    return 0;
}
