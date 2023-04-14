#include <iostream>
#include"linked.cpp"

using namespace std;


void menu(){
    cout << "1- Insert\n";
    cout << "2- Print list\n";
    cout << "3- Delete\n";
    cout << "1- Insert\n";
    cout << "0- Exit\n";
    cout << "Opcao: ";
}

int main(){
    
    LinkedList list;
    int option = -1;
    int number;

    while (option!=0){
        menu();
        cin >> option;
        if(option == 1){
            cout << "\nNumero para inserir: ";
            cin >> number;
            list.insertNode(number);
        }
        else if(option == 2)
            list.show();
        else if(3){
            cout << "\nNumero para remover: ";
            cin >> number;
            list.remove(number);
        }
        else 
            cout << "\nOpção Invalida!!\n";
    }
    



    return 0;
}