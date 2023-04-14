#include <stdio.h>
#include <stdlib.h>

//obs: dar enfase remover da arvore

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
        root->right = insert(root->right, no);
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

    int left = numbersElements(root->left);
    int right = numbersElements(root->right);

    return 1 + left + right;
}

PONT searchNo(PONT root, int value, PONT *father){
    PONT current = root;
    *father = NULL;
    while(current){
        if(current->value == value) return current;
        *father = current;
        if(value < current->value) current = current->left;
        else current = current->right;
    }
    return NULL;
}

// PONT removeElement(PONT root, int value){
//     PONT father, no, p , q;
//     no = searchNo(root, value, &father);
//     if(no == NULL){
//         printf("\nElemento não encontrado\n");
//         return root;
//     }
//     //quantos decendentes se sim só junta o elemento ao pai

//     if(!no->left || !no->right){
//         if(!no->left) q = no->right;
//         else q = no->left;
//     }
//     //tem descendentes
//     else{
//         p = no;
//         q = no->left;

//         //percorrer ate a folha, sem filho na direira p-> pai q
//         while(q->right){
//             p = q;
//             q = q->right;
//         }
//         if(p!=no){
//             p->right = q->left;
//             q->left = no->left;
//         }
//         q->right = no->right;
//     }
//     if(!father){
//         free(no);
//         return q;
//     }
//     if(value < father->value) father->left = q;
//     else father->right = q;
//     free(no);
//     return root;
// }

PONT findMin(PONT root){
    while(root->left != NULL) root = root->left;
    return root;
}

PONT findMax(PONT root){
    while(root->right != NULL) root = root->right;
    return root;
}

int countLeftChilds(PONT root){
    if(root == NULL) return 0;
    int count = countLeftChilds(root->left);

    return (count + 1);
}

int countRightChilds(PONT root){
    if(root == NULL) return 0;
    int count = countRightChilds(root->right);

    return (count + 1);
}

void treeprint(PONT root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "| " : "  ");
        printf("%d\n", root->value);
        treeprint(root->left, level + 1);
        treeprint(root->right, level + 1);
}

PONT removeElement(PONT root, int value){

    if(root == NULL){
        return root;
    }
    
    //find element
    else if(root->value > value)
        root->left = removeElement(root->left, value);
    else if(root->value < value)
        root->right = removeElement(root->right, value);
    else{
        //CASE NO CHILD 
        if (root->left == NULL && root->right ==NULL) {
            free(root);
            PONT temp = NULL;
            return temp;
        } else if (root->left == NULL) {
            PONT temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL){
            PONT temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        //caso com dois filhos
        else{
            
            int childsMinimum = countLeftChilds(root->right);
            int childsMax = countRightChilds(root->left);

            
            if(childsMax < childsMinimum){
                PONT temp = findMin(root->right);
                root->value = temp->value;
                root->right = removeElement(root->right, temp->value);
            }else{
                PONT temp = findMax(root->left);
                root->value = temp->value;
                root->left = removeElement(root->left, temp->value);
            }

            //possivel contagem para verificar o tamanho para ver se tira da direita ou esquerda
            //encontrar minino de uma arvore
            //    PONT temp = findMin(root->right);
            //troca o valor para o valor minimo
            //    root->value = temp->value;
            //vai realocando os valores
            //    root->right = removeElement(root->right, temp->value);
            
        }
    }

    return root;
}


//ordem crescente
void inOrder(PONT current){
    if(current != NULL){
        inOrder(current->left);
        printf("\n %d \n", current->value);
        inOrder(current->right);
    }
}

//ordem dos filhos primeiros(começa pela esquerda)
void posOrder(PONT current){
    if(current != NULL){
        posOrder(current->left);
        posOrder(current->right);
        printf("\n %d \n", current->value);
    }
}

//pais primeiros depois são apresentador os filhos
void preOrder(PONT current){
    if(current != NULL){
        printf("\n %d \n", current->value);
        posOrder(current->left);
        posOrder(current->right);
    }
}

void menu(){
    printf("Digite sua escolha:\n"
            " 1- Insert\n"
            " 2- Search\n"
            " 3- Numbers of elements\n"
            " 4- Remove\n"
            " 5- In Order\n"
            " 6- Pos Order\n"
            " 7- Pre Order\n"
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
            treeprint(head, 0);
            //printf("\n Numero de elementos: %d\n", numbersElements(head));
            break;

        case 4:
            printf("Digite o numero que deseja remover: ");
            scanf("\n%d", &value);
        
            head = removeElement(head, value);
            break;

        case 5:
            inOrder(head);
            break;
            
        case 6:
            posOrder(head);
            break;
            
        case 7:
            preOrder(head);
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            menu();
            break;
        }
    }

    return 0;
}