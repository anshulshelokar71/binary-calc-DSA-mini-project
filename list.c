#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// #include "list.h"
#include "stack.h"

void init(list *l)
{
    l->head = l->tail = NULL;
    l->dec = l->len = 0;
    l->sign = 1;
}

void insert(list *l, int pos, int ele)
{
    node *t, *p;
    if (pos < 0 || pos > l->len)
    {
        return;
    }
    t = (node *)malloc(sizeof(node));
    t->data = ele;
    if (l->head == NULL)
    {
        t->prev = NULL;
        t->next = NULL;
        l->head = t;
        l->tail = t;
        l->len++;
        return;
    }
    p = l->head;
    for (int i = 0; i < pos-1; i++)
    {
        p = p->next;
    }
    if (pos == 0)
    {
        t->next = l->head;
        l->head->prev = t;
        t->prev = NULL;
        l->head = t;
        l->len++;
        return;
    }
    if (pos != l->len)
    {
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
        l->len++;
        return;
    }
    if (pos == l->len)
    {
        p->next = t;
        l->tail = t;
        t->next = NULL;
        t->prev = p;
        l->len++;
        return;
    }
}

int delete(list *l, int pos)
{
    node *t, *p;
    int num;
    if (pos < 0 || pos >= l->len)
    {
        return 0;
    }
    p = l->head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    if(l->head == NULL) {
		return 0;
	}
    if (l->len == 1)
    {
        num = p->data;
        l->head = l->tail = p = NULL;
        l->len--;
        return num;
    }
    if (pos == 0)
    {
       num = p->data;
		p->next->prev = NULL;
		l->head = p->next;
		free(p);
		l->len--;
		return num;
    }
    if (pos == l->len - 1)
    {
        num = p->next->data;
		t = p->next;
		p->next = NULL;
		l->tail = p;
		free(t);
		l->len--;
		return num;
    }
    t = p->next;
    p->next = t->next;
    t->next->prev = p;
    num = t->data;
    free(t);
    l->len--;
    return num;
}

void append(list *l, int ele)
{
    insert(l, l->len, ele);
}

int length(list *l)
{
    return l->len;
}

int dec(list *l)
{
    return l->dec;
}

void traverse(list *l, int arg)
{
    node *p;
    int i = 0;
	int flag = 0, print = 0;
	int flag1 = 0;
    p = l->head;
    if (!p)
    {
        return;
    }
    do
    {
        if (l->sign == -1)
        {
            printf("-");
            l->sign = 1;
            flag = 1;
        }
        if (i == l->len - l->dec)
        {
            if (print != 1)
            {
                printf("0.");
                if (arg == 2)
                {
                    break;
                }
                print = 1;
            }
        }
        i++;
        if (p->data != 0 || i > l->len - l->dec - 2)
        {
            flag1 = 1;
        }
        if (flag1 == 1)
        {
            printf("%d", p->data);
        }
        if (i == l->len - l->dec)
        {
            if (print != 1)
            {
                printf(".");
                if(arg==2){
                    break;
                }
                print = 1;
            }
        }
        p=p->next;
    } while (p != NULL);
    if(flag == 1){
        l->sign = -1;
        flag = 0;
    }
}

int show(list *l, int pos)
{
    node *p;
    if (pos < 0 || pos > l->len)
        return 0;
    p = l->head;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    return p->data;
}

// int main(){
//     list l;
//     init(&l);
//     insert(&l,0,1);
//     insert(&l,1,2);
//     insert(&l,2,3);
//     insert(&l,3,4);
//     printf("%d",delete(&l,0));
//     return 0;
// }