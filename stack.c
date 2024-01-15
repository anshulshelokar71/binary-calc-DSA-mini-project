// #include"list.h"
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void s_init1(stack1 *s){
    s->i = 0;
}

void push1(stack1 *s,list *l){
    s->l[s->i] = l;
    (s->i)++;
}

list *pop1(stack1 *s){
    if(s->i==0){
        return NULL;
    }
    list *t = (list *)malloc(sizeof(list));
    t = s->l[s->i-1];
    (s->i)--;
    return t;
}

int empty1(stack1 *s){
    return s->i==0;
}

int full1(stack1 *s){
    return s->i==MAX;
}

void s_init2(stack2 *s){
    s->i = 0;
}

void push2(stack2 *s,list *l){
    s->l[s->i] = l;
    (s->i)++;
}

list *pop2(stack2 *s){
    if(s->i==0){
        return NULL;
    }
    list *t = (list *)malloc(sizeof(list));
    t = s->l[s->i-1];
    (s->i)--;
    return t;
}

int empty2(stack2 *s){
    return s->i==0;
}

int full2(stack2 *s){
    return s->i==MAX;
}


void c_init(cstack *s){
    s->i = 0;
}

void cpush(cstack *s,char op){
    s->a[s->i] = op;
    (s->i)++;
}

char cpop(cstack *s){
    if(cempty){
        return '0';
    }
    char t = s->a[s->i-1];
    (s->i)--;
    return t;
}

int cempty(cstack *s){
    return s->i==0;
}

int cfull(cstack *s){
    return s->i==MAX;
}