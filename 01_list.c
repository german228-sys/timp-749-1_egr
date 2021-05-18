
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
    struct node *head;  // начало 
    struct node *tail;  // конец 
} list;

typedef struct node {
    int value;          // значение узла
    struct node *next;  // ссылка на след
    struct node *pred;  // ссылка на пред
} node;

// делаем пустой список
void init(list *per){
    per->head = NULL;
    per->tail = NULL;
}


// проверка на заполненность списка
bool is_empty(list *per){
    if (per->head == NULL)
        return 1;
    else
        return 0;
}

// удалить все 
void clean(list *per){
    node* p1 = per->head;
    node* p2;
    while (p1->next != NULL){
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
    free(p1);
    init(per);
}


// вставить в конец
int push_back(list *per, int value){
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->value = value;
    Nnode->next = NULL;
    if (is_empty(per)){
        per->head = Nnode;
        per->tail = Nnode;
        Nnode->pred = NULL;
    }
    else{
        Nnode->pred = per->tail;
        per->tail->next = Nnode;
        per->tail = Nnode;
    }
    return 0;
}

// поиск элемента 
node *find(list *per, int value){
    node* p = per->head;
    while (p->next != NULL){
        if (p->value == value)
            return p;
        p = p->next;
    }
    if (p->value == value)
        return p;
    return NULL;
}



node *findNode(list* per, int n){
    int i;
    node* p = per->head;
    for (i = 1; i < n; i++)
        p = p->next;
    return p;

}

// вставка после указания места
int insert_after(list *per, node *n, int value){
    {
        node* Nnode;
        Nnode = (node*)malloc(sizeof(node));
        Nnode->value = value;
        Nnode->pred = n;
        if (n->next == NULL){
            Nnode->next = NULL;
            n->next = Nnode;
            per->tail = Nnode;
        }
        else{
            Nnode->next = n->next;
            Nnode->next->pred = Nnode;
            n->next = Nnode;
        }
        return 0;
    }
}

// вставка в начало
int push_front(list *per, int value){
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->value = value;
    Nnode->pred = NULL;
    if (is_empty(per)){
        per->head = Nnode;
        per->tail = Nnode;
        Nnode->next = NULL;
    }
    else{
        Nnode->next = per->head;
        per->head->pred = Nnode;
        per->head = Nnode;
    }
    return 0;
}

// вставка перед указанным
int insert_before(list *per, node *n, int value){
    if (n->pred == NULL){
        push_front(per, value);
        return 0;
    }
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->next = n;
    Nnode->pred = n->pred;
    Nnode->pred->next = Nnode;
    n->pred = Nnode;
    Nnode->value = value;
    return 0;
}

// удаление 1 эллемента по значению

int remove_first(list *per, int value){
    node* p1 = per->head;
    node* p2;
    while ((p1->value != value)&&(p1->next != NULL)){
        p2 = p1;
        p1 = p1->next;
    }
    if ((p1->next == NULL)&&(p1->value != value))
        return 1;
    else if ((p1->next == NULL)&&(p1->value == value)){
        p2->next = NULL;
        per->tail = p2;
    }
    else if (p1 == per->head) {
        per->head = p1->next;
        p1->next->pred = NULL;
    }
    else{
        p2->next = p1->next;
        p1->next->pred = p2;
    }
    free(p1);
    return 0;
}

// удаление ласт эллемента по значению

int remove_last(list *per, int value) {
    node *p1 = per->tail;
    node *p2;
    while ((p1->value != value) && (p1->pred != NULL)) {
        p2 = p1;
        p1 = p1->pred;
    }
    if ((p1->pred == NULL) && (p1->value != value))
        return 1;
    else if ((p1->pred == NULL) && (p1->value == value)){
        p2->pred = NULL;
        per->head = p2;
    }
    else if (p1 == per->tail){
        per->tail = p1->pred;
        p1->pred->next = NULL;

    }
    else {
        p2->pred = p1->pred;
        p1->pred->next = p2;
    }
    free(p1);
    return 0;
}

// вывод всего в прямом порядке

void print(list *per){
    node *p = per->head;
    while (p->next != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("%d", p->value);
    printf("\n");
}

// вывод всего в обратном порядке
void print_invers(list *per){
    node *p = per->tail;
    while (p->pred != NULL){
        printf("%d ", p->value);
        p = p->pred;
    }
    printf("%d", p->value);
    printf("\n");
}


int main() {
    list per;
    node* b;
    int n, i, input, k1, k2, k3;
    init(&per); // задание 1
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i++){ // задание 2
        (void)scanf("%d", &input);
        push_back(&per, input);
    }
    print(&per); // задание 3
    (void)scanf("%d %d %d", &k1, &k2, &k3); // задание 4
    b = find(&per, k1);
    if (b != NULL)
        k1 = 1;
    else
        k1 = 0;
    b = find(&per, k2);
    if (b != NULL)
        k2 = 1;
    else
        k2 = 0;
    b = find(&per, k3);
    if (b != NULL)
        k3 = 1;
    else
        k3 = 0;
    printf("%d %d %d\n", k1, k2, k3);
    (void)scanf("%d", &input); // задание 5
    push_back(&per, input);
    print_invers(&per); // задание 6
    (void)scanf("%d", &input); // задание 7
    push_front(&per, input);
    print(&per); // задание 8
    (void)scanf("%d %d", &n, &input); // задание 9
    b = findNode(&per, n);
    insert_after(&per, b, input);
    print_invers(&per); // задание 10
    (void)scanf("%d %d", &n, &input); // задание 11
    b = findNode(&per, n);
    insert_before(&per, b, input);
    print(&per); // задание 12
    (void)scanf("%d", &input); //задание 13
    remove_first(&per, input);
    print_invers(&per); // задание 14
    (void)scanf("%d", &input); //задание 15
    remove_last(&per, input);
    print(&per); // задание 16
    clean(&per); // задание 17
    return 0;
}


