#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Tree
{
struct Tree *Right;
struct Tree *Left;
double Data;
};
void init(struct Tree **t)
{
*t = (struct Tree *)malloc(sizeof(struct Tree));
(*t)->Right = NULL;
(*t)->Left = NULL;
(*t)->Data = 2147483648;
}

struct Tree* find(struct Tree *t, int value)
{
if (t->Data==value)
return t;
else
{
if (value < t->Data)
{
if (t->Left != NULL)
return(find(t->Left, value));
else
return NULL;
}
else
{
if (t->Right != NULL)
return(find(t->Right, value));
else
return NULL;
}
}
}
int find_with_output(struct Tree *t, int value)
{
if (t->Data == value)
{
printf("_ ");
if (t->Left != NULL)
printf("%d ", (int)t->Left->Data);
else
printf("_ ");
if (t->Right != NULL)
printf("%d", (int)t->Right->Data);
else
printf("_");
}
else
{
if (value < t->Data)
{
if (t->Left != NULL)
{
if (t->Left->Data == value)
{
printf("%d ", (int)t->Data);
if ((t->Left->Left) != NULL)
printf("%d ", (int)t->Left->Left->Data);
else
printf("_ ");
if ((t->Left->Right) != NULL)
printf("%d", (int)t->Left->Right->Data);
else
printf("_");
}
else
return(find_with_output(t->Left, value));
}
else
return 1;
}
else
{
if (t->Right != NULL)
{
if (t->Right->Data == value)
{
printf("%d ", (int)t->Data);
if ((t->Right->Left) != NULL)
printf("%d ", (int)t->Right->Left->Data);
else
printf("_ ");
if ((t->Right->Right) != NULL)
printf("%d", (int)t->Right->Right->Data);
else
printf("_");
}
else
return(find_with_output(t->Right, value));
}
else
return 1;
}
}
return 0;
}
void clean(struct Tree *t)
{
if (t != NULL)
{
if (t->Right != NULL)
clean(t->Right);
if (t->Left != NULL)
clean(t->Left);
free(t);
}
}
int insert(struct Tree *t, int value)
{
if (t->Data == 2147483648)
{
t->Data = value;
return 0;
}
if (t->Data == value)
return 1;
if (value > (t->Data))
{
if ((t->Right)!=NULL)
return(insert(t->Right, value));
else
{
t->Right=(struct Tree *)malloc(sizeof(struct Tree));
t->Right->Right = NULL;
t->Right->Left = NULL;
t->Right->Data = value;
return 0;
}
}
else
{
if ((t->Left) != NULL)
return(insert(t->Left, value));
else
{
t->Left = (struct Tree *)malloc(sizeof(struct Tree));
t->Left->Right = NULL;
t->Left->Left = NULL;
t->Left->Data = value;
return 0;
}
}
}
int deep(struct Tree *t)
{
int r=0, l=0;
if ((t->Right) != NULL)
r=deep(t->Right);
if ((t->Left) != NULL)
l = deep(t->Left);
if (r > l)
return (r+1);
return (l+1);
}
int remove_node(struct Tree **t, int value)
{
if ((*t)->Data == value)
{
if ((*t)->Right != NULL)
{
struct Tree *Temp = (*t)->Right, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
(*t)->Data = Temp->Left->Data;
Temp2=Temp->Left;
Temp->Left=Temp2->Right;
free(Temp2);
}
else
{
struct Tree *Temp;
(*t)->Data = (*t)->Right->Data;
Temp = (*t)->Right;
(*t)->Right = (*t)->Right->Right;
free(Temp);
}
}
else
{
struct Tree *Temp;
Temp = (*t);
(*t) = (*t)->Left;
free(Temp);
Temp = NULL;
}
return 0;
}
else
{
if (value < ((*t)->Data))
{
if ((*t)->Left != NULL)
return(remove_node(&((*t)->Left), value));
else
return 1;
}
else
{
if (((*t)->Right) != NULL)
return(remove_node(&((*t)->Right), value));
else
return 1;
}
}
}
int remove_min(struct Tree *t)
{
struct Tree *Temp = t, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
Temp2 = Temp->Left;
Temp->Left = Temp2->Right;
free(Temp2);
}
else
{
Temp = t->Right;
free(t);
t = Temp;
}
return 0;
}
int rotate_right(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A, *B, *C=(*t)->Right, *x=(*t)->Left, *y=(*t), *Temp =
(struct Tree *)malloc(sizeof(struct Tree));
if (x != NULL)
{
A = x->Left;
B = x->Right;
}
else
return 1;
Temp->Right = y;
Temp->Left = A;
Temp->Right->Right = C;
Temp->Right->Left = B;
Temp->Data = x->Data;
free(x);
(*t) = Temp;
return 0;
}
int rotate_left(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A = (*t)->Left, *B, *C, *x =
(*t), *y = (*t)->Right,
*Temp=(struct Tree *)malloc(sizeof(struct Tree));
if (y != NULL)
{
B = y->Left;
C = y->Right;
}
else
return 1;
Temp->Right = C;
Temp->Left = x;
Temp->Left->Right = B;
Temp->Left->Left = A;
Temp->Data = y->Data;
free(y);
(*t) = Temp;
return 0;
}
int print_tree(struct Tree *t)
{
if (t == NULL)
{
printf("-\n");
return 1;
}
struct Tree *Temp=t;
int Rang=0, i, j, k, sk;
int *comb;
Rang = deep(t);
comb = (int*)malloc(sizeof(int));
for (i = 0; i < Rang; i++)
{
if (i != 0)
{
comb = (int*)realloc(comb, i* sizeof(int));
for (j = 0; j < i; j++)
comb[j] = 0;
}
j = 1;
sk = i;
while (sk != 0)
{
j = j * 2;
sk--;
}
while (j != 0)
{
k = 0;
Temp = t;
for (k = 0; k < i; k++)
{
if (comb[k] == 0)
{
if ((Temp->Left) != NULL)
Temp = Temp->Left;
else
{
k = -1;
break;
}
}
else
{
if ((Temp->Right) != NULL)
Temp = Temp->Right;
else
{
k = -1;
break;
}
}
}
if (i != 0)
{
sk=i-1;
comb[sk]++;
while (1)
{
if (comb[sk] == 2)
{
comb[sk] = 0;
sk--;
if (sk < 0)
break;
else
comb[sk]++;
}
else
break;
}
}
if (k==-1)
printf("_");
else
printf("%d", (int)Temp->Data);
j--;
if (j != 0)
printf(" ");
}
printf("\n");
}
return 1;
}
int all(struct Tree *t)
{
if (t == NULL)
return 0;
int r, l;
l = all(t->Left);
r = all(t->Right);
return (l + r+1);
}
int main()
{
struct Tree *t;
int i;
double a;
init(&t);//1 
for (i = 0; i < 4; i++)
{
scanf("%lf", &a);
insert(t, a);
}
print_tree(t);//2 
printf("\n");
for (i = 0; i < 3; i++)//3 
{
scanf("%lf", &a);
insert(t, a);
}
print_tree(t);//4 
printf("\n");
for (i = 0; i < 2; i++)
{
scanf("%lf", &a);//5   6
a = find_with_output(t, a);
if (a == 1)
printf("-");
printf("\n\n");
}
scanf("%lf", &a);//7 
remove_node(&t, a);
print_tree(t);//8 
printf("\n");
while (1)//9 
{
a=rotate_left(&t);
if (a == 1)
break;
}
print_tree(t);//10 
printf("\n");
while (1)//11 
{
a = rotate_right(&t);
if (a == 1)
break;
}
print_tree(t);//12
printf("\n");
printf("%d\n\n", all(t));//13
clean(t);//14 
t = NULL;
print_tree(t);//15 
return 0;
}
