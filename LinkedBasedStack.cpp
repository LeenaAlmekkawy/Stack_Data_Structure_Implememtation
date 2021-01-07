//Linked-based implementation
#include <stdio.h>
#include <stdlib.h>
# define StackEntry int
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
}StackNode;
typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

void CreateStack(Stack *ps);

void Push (StackEntry e , Stack *ps);

void Pop( StackEntry *pe , Stack *ps);

void StackTop( StackEntry *pe , Stack *ps);

int StackEmpty(Stack *ps);

int StackFull(Stack *ps);

void ClearStack (Stack *ps);

void Display (StackEntry e);

void TraverseStack(Stack *ps , void(*pf)(StackEntry));

int StackSize(Stack *ps);

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

// --------------------------------

void CreateStack(Stack *ps)
{
    ps->top=NULL; //Access top
    ps->size=0;   // NULL is defined in <stdlib.h>
                  //the complexity is O(1)
}
void Push (StackEntry e , Stack *ps)
{
     StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
     pn->entry=e;
     pn->next=ps->top;
     ps->top=pn;
     ps->size++;
}

void Pop( StackEntry *pe , Stack *ps)
{    StackNode *pn;
    *pe=ps->top->entry;
    pn=ps->top;
    ps->top=ps->top->next;
    free(pn);
    ps->size--;

}
void StackTop( StackEntry *pe , Stack *ps)
{
     *pe=ps->top->entry;
    int k=*pe;
    printf("%d\n",k);
}
int StackEmpty(Stack *ps)
{
    if (ps->top==NULL)
         return 1;
    else
        return 0;
}
int StackFull(Stack *ps)
{
        return 0;  //the stack will never be full
}
void ClearStack (Stack *ps)
{
 StackNode *pn=ps->top;
 StackNode *qn=ps->top;
 while(pn)       // pn!=NULL
 {
     pn=pn->next;
 free(qn);
 qn=pn;
 }
 ps->top=NULL;
 ps->size=0;

}
void Display (StackEntry e)
{
   printf("%d " , e);  // The code of Display
}
void TraverseStack(Stack *ps , void(*pf)(StackEntry))
{   StackNode *pn=ps->top;
   while(pn)
   {
       (*pf)(pn->entry);
       pn=pn->next;
   }
    printf("\n");
}
int StackSize(Stack *ps)
{     return ps->size;
  /* or  -----> but this code is not efficient
    int x;
    StackNode *pn=ps->top;
    for (x=0 ; pn ; pn=pn->next)
          x++;
    return x; */
}

