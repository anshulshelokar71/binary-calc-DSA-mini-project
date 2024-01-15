#include<math.h>
#define PLUS 1
#define MINUS -1
#define PI 3.1415926535
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

void init(list *l);
void insert(list *l, int pos, int num);
int delete(list *l, int pos);
void traverse(list *l, int arg);
void append(list *l, int num);
int length(list *l);
int dec(list *l);
int show(list *l, int pos);
