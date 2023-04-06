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
