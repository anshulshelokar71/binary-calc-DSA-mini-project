#include<math.h>

typedef struct node{
    int data;
    int flag;
    struct node *next;
    struct node *prev;
}node;

typedef struct list{
    node *head,*tail;
    int len,dec,sign;
}list;
