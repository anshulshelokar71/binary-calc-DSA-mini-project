#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include"list.h"
#include<math.h>

#define PLUS 1
#define MINUS -1
#define PI 3.1415926535

void copy(list*l1,list*l2);
int compare(list *l1,list*l2);
int checkzero(list*l);
// double radian(list *l1);
list *add(list*l1,list*l2);
list *sub(list*l1,list*l2);
// list *mul(list*l1,list*l2);
// list *div(list*l1,list*l2);
// list *modulus(list*l1,list*l2);
// list *power(list*l1,list*l2);
#endif // NUMBER_H_INCLUDED
