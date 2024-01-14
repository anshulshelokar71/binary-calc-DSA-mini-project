#include"list.h"
#define MAX 2048

typedef struct stack1{
    int i;
    list *l[MAX];
}stack1;

void s_init1(stack1 *s);
void push1(stack1 *s,list *l);
list *pop1(stack1 *s);
int empty1(stack1 *s);
int full1(stack1 *s);



typedef struct stack2{
    int i;
    list *l[MAX];
}stack2;

void s_init2(stack2 *s);
void push2(stack2 *s,list *l);
list *pop2(stack2 *s);
int empty2(stack2 *s);
int full2(stack2 *s);

typedef struct cstack{
    char a[MAX];
    int i;
}cstack;

void c_init(cstack *s);
void cpush(cstack *s);
char cpop(cstack *s);
int cempty(cstack *s);
int cfull(cstack *s);

