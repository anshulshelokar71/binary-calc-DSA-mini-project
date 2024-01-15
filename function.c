#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.c"
// #include "list.h"
// #include "stack.h"
// #include "stack.c"
// #include "function.h"

list *add(list *l1, list *l2);
list *sub(list *l1, list *l2);

void copy(list *l1, list *l2)
{
    init(l2);
    l2->sign = l1->sign;
    l2->dec = l1->dec;
    for (int i = 0; i < l1->len; i++)
    {
        append(l2, show(l1, i));
    }
    return;
}

int compare(list *l1, list *l2)
{
    if (l1->sign == 1 && l2->sign == -1)
    {
        return 1;
    }
    if (l1->sign == -1 && l2->sign == 1)
    {
        return -1;
    }
    int a = dec(l1) - dec(l2);
    if (a > 0)
    {
        int i = 0;
        while (i < a)
        {
            append(l2, 0);
            l2->dec++;
            i++;
        }
    }
    else if (a < 0)
    {
        int i = 0;
        while (i < (-a))
        {
            append(l1, 0);
            l1->dec++;
            i++;
        }
    }
    int b = length(l1) - length(l2);
    if (b > 0)
    {
        int i = 0;
        while (i < b)
        {
            insert(l2, 0, 0);
            i++;
        }
    }
    else if (b < 0)
    {
        int i = 0;
        while (i < (-b))
        {
            insert(l1, 0, 0);
            i++;
        }
    }
    for (int i = 0; i < length(l1); i++)
    {
        if (show(l1, i) > show(l2, i))
        {
            return 1;
        }
        else if (show(l1, i) < show(l2, i))
        {
            return -1;
        }
    }
    return 0;
}

int checkzero(list *l)
{
    int flag = 0;
    for (int i = 0; i < length(l); i++)
    {
        if (show(l, i) != 0)
        {
            flag = 1;
        }
    }
    return flag;
}

list *add(list *l1, list *l2)
{
    int sign1, sign2;
    sign1 = l1->sign;
    sign2 = l2->sign;
    list *ans = (list *)malloc(sizeof(list));
    init(ans);
    int a = dec(l1) - dec(l2);
    if (a > 0)
    {
        int i = 0;
        while (i < a)
        {
            append(l2, 0);
            l2->dec++;
            i++;
        }
    }
    else if (a < 0)
    {
        int i = 0;
        while (i < (-a))
        {
            append(l1, 0);
            l1->dec++;
            i++;
        }
    }

    if (l1->sign != l2->sign)
    {
        if (l1->sign == -1)
        {
            l1->sign = 1;
            ans = sub(l2, l1);
        }
        else if (l2->sign == -1)
        {
            l2->sign = 1;
            ans = sub(l1, l2);
        }
    }
    else if (l1->sign == l2->sign)
    {
        if (l1->sign == -1)
        {
            ans->sign = -1;
            // l1->sign=l2->sign=1;
        }
        else if (l1->sign == 1)
        {
            ans->sign = 1;
        }
        int num = 0;
        int i = length(l1);
        int j = length(l2);
        int carry = 0;
        while (i != 0 || j != 0)
        {
            if (i == 0)
            {
                num = show(l2, j - 1) + carry;
                carry = num / 10;
                num = num % 10;
                insert(ans, 0, num);
                j--;
            }
            else if (j == 0)
            {
                num = show(l1, i - 1) + carry;
                carry = num / 10;
                num = num % 10;
                insert(ans, 0, num);
                i--;
            }
            else
            {
                num = show(l1, i - 1) + show(l2, j - 1) + carry;
                carry = num / 10;
                num = num % 10;
                insert(ans, 0, num);
                i--;
                j--;
            }
        }
        ans->dec = dec(l1);
        if (carry != 0)
        {
            insert(ans, 0, carry);
        }
    }
    l1->sign = sign1;
    l2->sign = sign2;
    return ans;
}

list *sub(list *l1, list *l2)
{
    int sign1, sign2;
    sign1 = l1->sign;
    sign2 = l2->sign;
    list *ans = (list *)malloc(sizeof(list));
    init(ans);
    int a = dec(l1) - dec(l2);
    if (a > 0)
    {
        int i = 0;
        while (i < a)
        {
            append(l2, 0);
            l2->dec++;
            i++;
        }
    }
    else if (a < 0)
    {
        int i = 0;
        while (i < (-a))
        {
            append(l1, 0);
            l1->dec++;
            i++;
        }
    }
    static int flag = 0;
    int num;

    if (l1->sign != l2->sign)
    {
        if (l1->sign == -1)
        {
            l2->sign = -1;
            ans = add(l1, l2);
            ans->sign = -1;
        }
        else if (l2->sign == -1)
        {
            l2->sign = 1;
            ans = add(l1, l2);
            ans->sign = 1;
        }
    }
    else if (l1->sign == l2->sign)
    {
        if (l1->sign == -1)
        {
            l1->sign = 1;
            l2->sign = 1;
            ans = sub(l2, l1);
        }
        if (l1->sign == 1)
        {
            if (compare(l1, l2) >= 0)
            {
                if (flag != 1)
                {
                    ans->sign = 1;
                }
                else
                {
                    ans->sign = -1;
                }
                int a = 0;
                int i, j;
                i = length(l1);
                j = length(l2);
                while (i != 0 || j != 0)
                {
                    if (j == 0)
                    {
                        num = show(l1, i - 1);
                        i--;
                        insert(ans, 0, num);
                    }
                    else
                    {
                        int n1 = show(l1, i - 1);
                        i--;
                        int n2 = show(l2, j - 1);
                        j--;
                        if (n1 >= n2)
                        {
                            num = n1 - n2;
                            insert(ans, 0, num);
                        }
                        else
                        {
                            int d = 0;
                            while (!(a = delete (l1, i - 1)))
                            {
                                i--;
                                d++;
                            }
                            insert(l1, i - 1, a - 1);
                            for (int m = 0; m < d; m++)
                            {
                                i++;
                                insert(l1, i - 1, 9);
                            }
                            num = 10 + n1 - n2;
                            insert(ans, 0, num);
                        }
                    }
                }
            }
            else if (compare(l1, l2) < 0)
            {
                flag = 1;
                ans = sub(l2, l1);
                ans->sign = -1;
            }
        }
    }
    ans->dec = l1->dec;
    flag = 0;
    l1->sign = sign1;
    l2->sign = sign2;
    return ans;
}

list *multi(list *l1, list *l2)
{
    list *ans;
    ans = (list *)malloc(sizeof(list));
    init(ans);
    int tsign, sign1, sign2;
    sign1 = l1->sign;
    sign2 = l2->sign;
    if (checkzero(l1) == 0)
    {
        return l1;
    }
    if (checkzero(l2) == 0)
    {
        return l2;
    }
    if (l1->sign == l2->sign)
    {
        tsign = 1;
        l1->sign = l2->sign = 1;
    }
    else
    {
        tsign = -1;
        l1->sign = l2->sign = 1;
    }
    int a = length(l1) - length(l2);
    if (a < 0)
    {
        ans = multi(l2, l1);
        return ans;
    }
    else
    {
        int n = length(l2) - 1, i, j;
        int x = length(l2), y = length(l1);
        int arr[2 * y];
        for (i = 0; i < 2 * y; i++)
        {
            arr[i] = 0;
        }
        int num1 = 0, num2 = 0;
        int k = 2 * y - 1;
        for (i = 0; i < x; i++)
        {
            int m = length(l1) - 1;
            int carry1 = 0, carry2 = 0;
            for (int j = k - i; j > y - 2; j--)
            {
                if (m != -1 && n != -1)
                {
                    num1 = show(l1, m) * show(l2, n) + carry1;
                    m--;
                    carry1 = num1 / 10;
                    num1 = num1 % 10;
                    num2 = arr[j] + num1 + carry2;
                    carry2 = num2 / 10;
                    num2 = num2 % 10;
                    arr[j] = num2;
                }
                else
                {
                    break;
                }
            }
            arr[j] = carry1 + carry2 + arr[j];
            y--;
            n--;
        }
        j = 0;
        for (i = 2 * length(l1) - 1; i > y - 1 && i >= 0; i--)
        {
            insert(ans, 0, arr[i]);
            j++;
        }
        ans->dec = l1->dec + l2->dec;
        ans->sign = tsign;
        l1->sign = sign1;
        l2->sign = sign2;
        return ans;
    }
}

list *division(list *l1,list *l2){
    if(checkzero(l2)==0){
        printf("ARITHMATIC EXCEPTION: dividing by zero\n");
        return NULL;
    }
    list *ans;
    ans=(list *)malloc(sizeof(list));
    list *t;
    t = (list *)malloc(sizeof(list));
    init(t);
    init(ans);
    int m,sign1,sign2;
    sign1=l1->sign;
    sign2=l2->sign;
    if(l1->sign==l2->sign){
        ans->sign=1;
        l1->sign=l2->sign=1;
    }else{
        ans->sign=-1;
        l1->sign=l2->sign=1;
    }

    int a,b;
    m = l1->dec-l2->dec;
    int i , j, k ,num;
    a = l1->dec;
    b=l2->dec;
    l1->dec=l2->dec=0;
    for(i=0;i<length(l1);i++){
        num =show(l1,i);
        append(t,num);
        if(compare(t,l2)<0){
            append(ans,0);
        }else{
            int d =0;
            while(1){
                t = sub(t,l2);
                d++;
                if(compare(t,l2)<0){
                    break;
                }
            }
            append(ans,d);
        }
    }
    j=0;
    k=0;
    while(j<10){
        append(t,0);
        int d = 0;
        while(compare(t,l2)>=0){
            t = sub(t,l2);
            d++;
        }
        append(ans,d);
        k++;
        j++;
    }
    ans->dec = 10 + m;
	l1->dec = a;
	l2->dec = b;
	l1->sign = sign1;
	l2->sign = sign2;
	return ans;
}
list *modulus(list *l1, list *l2)
{
	if (checkzero(l2) == 0)
	{
		printf("INVALID INPUT:modulo by zero");
		return NULL;
	}
	list *result;
	result = (list *)malloc(sizeof(list));
	list *temp;
	temp = (list *)malloc(sizeof(list));
	init(temp);
	init(result);
	list *l3;
	l3 = (list *)malloc(sizeof(list));
	init(l3);
	copy(l2, l3);
	int m, sign1, sign2;
	sign1 = l1->sign;
	sign2 = l2->sign;
	if (l1->sign == l2->sign)
	{
		result->sign = 1;
		l1->sign = l2->sign = 1;
	}
	else
	{
		result->sign = -1;
		l1->sign = l2->sign = 1;
	}

	int a, b;
	m = length(l1);
	int i, j, num;

	a = dec(l1);
	b = dec(l2);
	if (dec(l1) != 0)
	{
		l1->len = l1->len - dec(l1);
	}
	if (l3->dec != 0)
	{
		i = dec(l3);
		for (j = 0; j < i; j++)
		{
			delete(l3, l3->len);
		}
	}
	for (i = 0; i < l1->len; i++)
	{
		num = show(l1, i);
		append(temp, num);
		if (compare(temp, l3) < 0)
		{
			append(result, 0);
		}
		else
		{
			int d = 0;
			while (1)
			{
				temp = sub(temp, l3);
				d++;
				if (compare(temp, l3) < 0)
					break;
			}
			append(result, d);
		}
	}
	l1->len = m;
	l1->sign = sign1;
	l2->sign = sign2;
	l1->dec = a;
	l2->dec = b;
	return temp;
}

list *power(list *l1, list *l2)
{
	list *result = (list *)malloc(sizeof(list));
	init(result);
	append(result, 1);
	list *c1 = (list *)malloc(sizeof(list));
	init(c1);
	append(c1, 1);
	list *l3 = (list *)malloc(sizeof(list));
	init(l3);
	list *c2 = (list *)malloc(sizeof(list));
	init(c2);
	list *c0 = (list *)malloc(sizeof(list));
	init(c0);
	int sign = l1->sign;
	append(c2, 2);
	append(c0, 0);
	copy(l2, l3);
	if (l2->sign == 1)
	{
		while (checkzero(l3) != 0)
		{
			result = multi(result, l1);
			l3 = sub(l3, c1);
		}
	}
	else if (l2->sign == -1)
	{
		while (checkzero(l3) != 0)
		{
			result = division(result, l1);
			l3 = add(l3, c1);
		}
	}
	l1->sign = sign;
	if (l1->sign == -1)
	{
		if (compare(modulus(l2, c2), c0) == 0)
			result->sign = 1;
		else
			result->sign = -1;
	}
	return result;
}

// int main()
// {
//     printf("Hello");
//     return 0;
// }