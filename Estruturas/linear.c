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
    printf("\n");
}

PONT createPont(int value){
    PONT newValue = malloc(sizeof(ELEMENT));
    newValue->value = value;
    newValue->prox = NULL;
    return newValue;
}

void insert(LIST* list, int value){

    PONT newValue = createPont(value);

    if(!newValue)
        return;    
    // if(list == NULL){
    //     printf("BLABLABLABLALBALBLABLALBLABLALBL");
    //     list->start = newValue;
    // }

    
    PONT current= list->start;
    PONT previous = NULL;
    while (current != NULL && current->value < value)
    {   
        previous = current;
        current = current->prox;
    }
    if(previous == NULL){
        list->start = newValue;
        newValue->prox = current;
    }else{
        previous->prox = newValue;
        newValue->prox = current;
    }
    
}

void deleteElement(LIST* list, int value){
    PONT current= list->start;
    PONT delete = NULL;
    PONT previous = NULL;

    if(value== current->value){
        delete = current;
        list->start = current->prox;
        free(delete);
        return;
    }

    while (current != NULL && current->value<value)
    {   
        previous = current;
        current = current->prox;
    }
    
    if( current->value== value){
        delete = current;
        current = current->prox;
        previous-> prox = current;
        free(delete);
        printf("Element deleted!!\n");
    }else{
        printf("Elemento not found!!\n");
    }
    
}

void cleanList(LIST* list){
    PONT end = list->start;
    while(end!=NULL){
        PONT delete = end;
        end = end->prox;
        free(delete);
    }
    list->start = NULL;
}

void menu(){
    printf("Digite sua escolha:\n"
            " 1- Insert a element\n"
            " 2- Delete a element\n"
            " 3- Showlist\n"
            " 4- Clean list\n"
            " 0- Exit\n");
}

int main(){

    LIST list;
    inicializeList(&list);

    int option = -1;
    int value = 0;

    while(option!=0){
        menu();
        printf("Escolha: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite um numero inteiro: ");
            scanf("\n%d", &value);
            insert(&list, value);
            printf("\n");
            break;

        case 2:
            if(list.start == NULL){
                printf("\nLista vazia \n");
                break;
            }
            printf("Digite um numero que deseja deletar: ");
            scanf("\n%d", &value);
            deleteElement(&list, value);
            printf("\n");
            break;

        case 3:
            if(list.start == NULL)
                printf("\nLista vazia \n");
            showList(&list);
            
            break;

        case 4:
            cleanList(&list);
            
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            menu();
            break;
        }
    }

    return 0;
}