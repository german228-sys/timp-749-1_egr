#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Tree
{
  struct Tree *Right;
  struct Tree *Left;
  double Data;
};
int glubina(struct Tree *t)
{
  int prav = 0, lev = 0;
  if ((t->Right) != NULL)
  prav = glubina(t->Right);
  if ((t->Left) != NULL)
  lev = glubina(t->Left);
  if (prav > lev)
  return (prav + 1);
  return (lev + 1);
}
int insert(struct Tree *t, int value)
{
  if (t->Data == value)
  return 1;
  if (value > (t->Data))
  {
    if ((t->Right) != NULL)
    return(insert(t->Right, value));
    else
    {
      t->Right = (struct Tree *)malloc(sizeof(struct Tree));
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
void init(struct Tree **t, int value)
{
  *t = (struct Tree *)malloc(sizeof(struct Tree));
  (*t)->Right = NULL;
  (*t)->Left = NULL;
  (*t)->Data = value;
}
int print_width(struct Tree *t)
{
  struct Tree *Temp = t;
  int Rang = 0, i, j, k, sk, Spaces = 0;
  int *comb;
  Rang = glubina(t);
  comb = (int*)malloc(sizeof(int));
  for (i = 0; i < Rang; i++)//обход по рангам
  {
    if (i != 0)//зануление
    {
      comb = (int*)realloc(comb, i * sizeof(int));
      for (j = 0; j < i; j++)
      comb[j] = 0;
    }
    j = 1;
    sk = i;
    while (sk != 0)
    {
      j = j * 2;//сколько элементов на одном ранге
      sk--;
    }
    while (j != 0)
    {
      k = 0;
      Temp = t;
      for (k = 0; k < i; k++)//проход до нужного узла
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
        sk = i - 1;
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
      if (k != -1)//проверка на существование элемента
      {
      if (Spaces == 1)
      {
        printf(" ");
        Spaces = 1;
      }
      printf("%d", (int)Temp->Data);
      Spaces = 1;
    }
    j--;
  }
  }
  return 0;
}
int main()
{
  struct Tree *t;
  double val;
  int i;
  scanf("%lf", &val);
  init(&t, val);
  for (i = 0; i < 6; i++)
  {
    scanf("%lf", &val);
    insert(t, val);
  }
  print_width(t);
  return 1;
}
