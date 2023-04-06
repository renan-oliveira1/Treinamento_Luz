#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int chave;
} ELEMENT;

typedef struct{
    int elements[MAX];
    int top;
} STACK;

void inicializeStack(STACK* stack){
    stack->top = -1;
}


void showStack(STACK* stack){
    printf("\n");
    for(int i=0; i<= stack->top; i++){
        printf(" %d ", stack->elements[i]);
    }
    printf("\n");
    printf("\n");
}

void push(STACK* stack, int value){
    if(stack->top >= MAX-1){
        printf("\n Stack IS FULL \n");
        return;
    }
    stack->top = stack->top+1;
    stack->elements[stack->top] = value;
    printf("\n Element inserted \n");
}

int pop(STACK* stack){
    if(stack->top == -1){
        printf("\n Stack IS EMPTY ALREADY!! \n");
        return;
    }
    int deleted = stack->elements[stack->top];
    stack->top = stack->top-1;
    printf("\n Element deleted: %d\n", deleted);
}

void clean(STACK* stack){
    stack->top = -1;
}

void menu(){
    printf("Digite sua escolha:\n"
            " 1- Insert\n"
            " 2- Delete\n"
            " 3- Show stack\n"
            " 4- Clean\n"
            " 0- Exit\n");
}

int main(){

    STACK stack;
    inicializeStack(&stack);

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
            push(&stack, value);
            printf("\n");
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            if(stack.top == -1){
                printf("\n Empty stack!! \n");
                break;
            }
            showStack(&stack);
            
            break;

        case 4:
            clean(&stack);
            
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            menu();
            break;
        }
    }

    return 0;
}