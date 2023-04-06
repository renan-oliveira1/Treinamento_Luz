#include <stdio.h>
#include <stdlib.h>

typedef struct aux{
    int value;
    struct aux* prox;
} ELEMENT;

typedef ELEMENT* PONT;

typedef struct{
    PONT start;
} LIST;

void inicializeList(LIST* list){
    list->start = NULL;
}

int size(LIST* list){
    PONT end = list->start;
    int size = 0;

    while (end!=NULL){
        size++;
        end = end->prox;
    }

    return size;
}

void showList(LIST* list){
    PONT end = list->start;
    printf("\n");
    while(end!=NULL){
        printf("%i ", end->value);
        end = end->prox;
    }
    printf("\n");
}

PONT searchSequential(LIST* list, int value){
    PONT element = list->start;
    while(element!=NULL){
        if(element->value) return element;
        element = element->prox;
    }
    return NULL;
}

PONT searchSequentialOrd(LIST* list, int value){
    PONT element = list->start;
    while(element != NULL && element<value) element = element->prox;
    if(element != NULL && element->value == value) return element;
    return NULL;
}

PONT searchSpotToInsert(LIST* list, int value, PONT* ant){
    *ant = NULL;
    PONT current = list->start;
    while(current!=NULL && current->value < value){
        *ant = current;
        current = current->prox;
    }
    if( current != NULL && current->value == value )
        return current;
    return NULL;

    //retorna null se for maior, retorna o ponteiro do elemento (caso for um array vazio retorn null)
}


int insert(LIST* list, PONT element){
    int value = element->value;
    PONT previous, i;
    i = searchSpotToInsert(list, value, &previous);
    if(i != NULL) return 0;
    i = (PONT) malloc(sizeof(ELEMENT));
    i->value = value;
    if(previous == NULL){
        i->prox = list->start;
        list->start = i;
    }else{
        i->prox = previous->prox;
        previous->prox = i;
    }
    return 1;
}

int deleteElement(LIST* list, int value){
    PONT previous, i;
    i = searchSpotToInsert(list, value, &previous);
    if(i==NULL) return 0;
    if(previous==NULL) list->start = i->prox;
    else previous->prox = i->prox;
    free(i);
    return 1;
}

void rebootList(LIST* list){
    PONT end = list->start;
    while(end!=NULL){
        PONT delete = end;
        end = end->prox;
        free(delete);
    }
    list->start = NULL;
}

int main(){
    LIST list;
    inicializeList(&list);

}