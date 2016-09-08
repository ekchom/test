#include <string>
#include <iostream>
using namespace std; 
int count;
void subString(char *s) 
{  
    while (*s != '\0')
    {
        int x=0;
        while (*(s+x) != '\0') 
        { 
                int j=0;
                for (j=0;j<=x;j++) 
                        cout<<*(s+j);
                cout<<endl;
                x++;
        }
        s++;


    }
} 
int main() 
{ 
        const char *s="abcd";
        subString((char *)s);
}
