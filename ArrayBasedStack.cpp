//Array-based implementation
#include <stdio.h>
#include <stdlib.h>
# define StackEntry int
# define MAXSTACK 100
typedef struct stack{
     int top;
     StackEntry entry[MAXSTACK];
} Stack;
void CreateStack(Stack *ps);

void Push (StackEntry e , Stack *ps);

void Pop( StackEntry *pe , Stack *ps);

int StackFull(Stack *ps);

int StackEmpty(Stack *ps);

void StackTop( StackEntry *pe , Stack *ps);

void StackTop2( StackEntry *pe , Stack *ps);

int StackSize(Stack *ps);

void ClearStack (Stack *ps);

void TraverseStack(Stack *ps , void(*pf)(StackEntry));

void Display (StackEntry e);

int main()
{
    StackEntry e;
    Stack s;
    int x;
 CreateStack(&s);
 if (!StackFull(&s))  //Precondition
 Push(5,&s);
 Push(6,&s);
  Push(1,&s);
        printf("stack is  : ");
  TraverseStack(&s,&Display);
  printf("top : ");
StackTop(&e,&s);
 if (!StackEmpty(&s))
 {
     Pop(&e , &s);
 }
    printf("the last element was removed\n");
    printf("top : ");
 StackTop(&e , &s);
  x=StackSize(&s);
  printf("size : %d\n", x);
   ClearStack(&s);
         printf("the Stack now is clear\n");
     x=StackSize(&s);
  printf("size : %d\n", x);
    return 0;
}

//-----------------------------------------

void CreateStack(Stack *ps)
{
    ps->top=0; //Access top
}
void Push (StackEntry e , Stack *ps)
{
     ps->entry[ps->top]=e;
     ps->top++;
}
void Pop( StackEntry *pe , Stack *ps)
{
    ps->top--;
    *pe=ps->entry[ps->top];
}
int StackFull(Stack *ps)
{
    if (ps->top==MAXSTACK)
         return 1;
    else
        return 0;
}
int StackEmpty(Stack *ps)
{
    if (ps->top==0)
         return 1;
    else
        return 0;
}
void StackTop( StackEntry *pe , Stack *ps)
{
    *pe=ps->entry[ps->top-1];
    int k=*pe;
    printf("%d\n",k);
}
// Another implementation for (StackTop) but it is slower
void StackTop2( StackEntry *pe , Stack *ps)
{
    Pop(pe,ps);
    Push(*pe, ps);
}
int StackSize(Stack *ps)
{
    return ps->top;
}
void ClearStack (Stack *ps)
{

    ps->top=0;
}
void Display (StackEntry e)
{
   printf("%d " , e);  // The code of Display
}
void TraverseStack(Stack *ps , void(*pf)(StackEntry))
{
    for (int i=ps->top ; i>0 ; i--)
    {
       (*pf)(ps->entry[i-1]);

    }
    printf("\n");
}





