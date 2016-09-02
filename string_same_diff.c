/* INput is Two String, Output is two string named same and diff which contains charcter which are same and different in both the input string, respectively */ 
/* If Input is "abhishek"  and "kabra" then O/p in same string is 
Same - "abk" 
Diff "hishera" 
*/ 

#include <stdio.h>
#include <stdlib.h>
#define ASCII_MAX 256 
void populate_same_diff_Str(char *input1, char *input2, char *same, char *diff) 
{
	char *iter1, *iter2;
	int refCount_Arr1[ASCII_MAX]={0}; 
	int refCount_Arr2[ASCII_MAX]={0}; 
	iter1= input1; 
	iter2= input2; 
	if (!input1 || !input2 || !same || !diff)
		return;
	while (*iter1 !='\0')
	{
		refCount_Arr1[*iter1]++;
		iter1++;
	}

	while (*iter2 !='\0')
	{
		refCount_Arr2[*iter2]++;
		iter2++;
	}
	
	iter1= input1; 
	while (*iter1!='\0') 
	{
		if (refCount_Arr2[*iter1])
		{
			refCount_Arr2[*iter1]--;
			*same = *iter1;
			same++;
		} 
		else 
		{
			*diff = *iter1;
			diff++;
		}
		iter1++;
	}
	iter2=input2;
	while (*iter2!='\0') 
	{
		if (refCount_Arr1[*iter2])
		{ 
				/* ALready checked by first loop */
		}
		else 
		{
			*diff = *iter2;
			diff++;
		}
		iter2++;
	}
	*diff='\0';
	*same = '\0';
}
int main() 
{
#define MAX_LEN 1000
		while (1) 
		{
				char input1[MAX_LEN]={0}, input2[MAX_LEN]={0}, diff[MAX_LEN*2]={0}, same[MAX_LEN]={0};
				printf ("\n Press Ctrl+C to exit "); 
				printf ("\n Enter first input string, max Len %d ", MAX_LEN);
				scanf("%s", input1);
				printf ("\n Enter second input string, max Len %d ", MAX_LEN);
				scanf("%s", input2);
				populate_same_diff_Str(input1, input2, same, diff);
				printf ("\n Same String is %s", same);
				printf ("\n Diff String is %s", diff);
		}
}
