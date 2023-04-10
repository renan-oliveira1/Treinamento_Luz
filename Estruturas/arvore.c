#include <stdio.h>
#include <stdlib.h>


typedef struct aux{
    int value;
    struct aux *left, *right;
} NO;

typedef NO* PONT;

PONT initialize(){
    return NULL;
}

PONT createNo(int value){
    PONT new = (PONT) malloc(sizeof(NO));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

PONT insert(PONT root, PONT no){
    if(root==NULL) return no;
    if(root->value > no->value)
        root->left = insert(root->left, no);
    else
        root->right = insert(root->left, no);
    return root;
}

int search(PONT root, int value){
    if(root == NULL) return 0;
    if(root->value == value) return value;
    if(root->value > value) search(root->left, value);
    else search(root->right, value);
}

void searchElement(PONT root, int value){
    int found;
    found = search(root, value);
    if(found == 0) printf("\n Element %d not found!!\n", value);
    else printf("\n Element %d found!!\n", value);

}

int numbersElements(PONT root){
    if(root == NULL) return 0;
    return numbersElements(root->left)
        + 1
        + numbersElements(root->right);
}



void menu(){
    printf("Digite sua escolha:\n"
            " 1- Insert\n"
            " 2- Search\n"
            " 3- Numbers of elements\n"
            " 0- Exit\n");
}

int main(){

    PONT head = initialize();

    int option = -1;
    int value = 0;

     while(option!=0){
        menu();
        printf("Escolha: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite a inserir: ");
            scanf("\n%d", &value);
        
            PONT newValue = createNo(value);
            head = insert(head, newValue);
            printf("\n");
            break;
        case 2:
            printf("Digite a procurar: ");
            scanf("\n%d", &value);
            searchElement(head, value);
            printf("\n");
            break;

        case 3:
            
            printf("\n Numero de elementos: %d\n", numbersElements(head));
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            menu();
            break;
        }
    }

    return 0;
}