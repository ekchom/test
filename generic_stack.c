#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack
{
        int numElement;
        int sizeElement;
        int top;
        void *buffer;
} stack;
typedef enum status{ 
        OK=1,
        TRUE=OK,
        FAIL=0,
        FALSE=FAIL
}tStatus;
#define BASE_TOP 0
tStatus initStack(int numEle, int sizeEle, stack *s) 
{ 
        tStatus status=OK;
        if (numEle<=0 || sizeEle<=0 || !s)
                return FAIL;
        s->numElement = numEle;
        s->sizeElement = sizeEle;
        s->top = BASE_TOP;
        s->buffer = (void *)malloc(numEle*sizeEle);
        memset (s->buffer, 0, s->numElement*s->sizeElement);
        if (!s->buffer)
                return FAIL;
        return status; 
} 
int is_empty(stack *s) 
{
        if (!s || (s->top == BASE_TOP))
                return TRUE;
        else 
                return FALSE;
}
int is_full(stack *s) 
{
        if (!s || (s->top == (s->numElement))) 
                return TRUE;
        return FALSE;
}
void freeStack(stack *s) 
{
        if (!s) 
                return ;
        free(s->buffer);
        memset(s, 0, sizeof(*s));
}
tStatus push(stack *s, void *data) 
{
    tStatus status = OK;
    char *dest=NULL;
    if (!s|| !data) 
            return FAIL;
    if (is_full(s))
            return FAIL;
    dest = (char *)s->buffer + (s->sizeElement*(s->top));
    memcpy(dest, (void *)&data, s->sizeElement);
    (s->top)++;
    return OK;
}
void * pop(stack *s)
{  
    void *dest = NULL;
    if (!s) 
            return dest;
    if (is_empty(s))
            return dest; 
    dest = malloc(s->sizeElement);
    s->top--;
    memcpy((char *)dest, ((char *) (s->buffer) +s->sizeElement*s->top), s->sizeElement);
    return dest;
} 
void *pop_v2(stack *s) 
{
    void *dest = NULL;
    if (is_empty(s))
            return dest; 
    s->top--;
    return ((char *)(s->buffer) +s->sizeElement*s->top);
}
int main() 
{
        stack s; 
        int a[]={0,1,2,3,4,5,6,7,8};
        int i=0;
        char *d=NULL;
        initStack(100,4,&s);
        while (i<sizeof(a)/sizeof(a[0]))
                push(&s,(void *)a[i++]);
        while ((d=pop(&s))!=NULL) 
        {
                printf (" %d \n", *d);
                free(d);
        }
        freeStack(&s);
       
        initStack(100,4,&s);
        char *str[]={"My" , "Name ", "Is ", "Abhishek Kabra"};
        i=0;
        while (i<sizeof(str)/sizeof(str[0]))
               push(&s, str[i++]);
        while ((d=pop(&s))!= NULL)
        { 
                char *x = (*(int *)d);
                printf ("%s \n",  x);
                free(d);
        }
        freeStack(&s);
        i=0;
        initStack(100,4,&s);
        while (i<sizeof(a)/sizeof(a[0]))
                push(&s,(void *)a[i++]);
        while ((d=pop_v2(&s))!=NULL) 
        {
                printf (" %d \n", *(int *)d);
        }
        freeStack(&s);

        initStack(100,4,&s);
        i=0;
        while (i<sizeof(str)/sizeof(str[0]))
               push(&s, str[i++]);
        while ((d=pop(&s))!= NULL)
        { 
                printf ("%s \n",  *(int *)d); //d contain buffer position where char * (string address is stored ), 
        }
        freeStack(&s);

}


