#include <iostream>
#include"stack.cpp"

using namespace std;


void menu(){
    cout << "1- Insert\n";
    cout << "2- Print\n";
    cout << "3- Delete\n";
    cout << "0- Exit\n";
    cout << "Opcao: ";
}

int main(){
    
    Stack stack;
    int option = -1;
    int number;

    while (option!=0){
        menu();
        cin >> option;
        if(option == 1){
            cout << "\nNumero para inserir: ";
            cin >> number;
            stack.push(number);
        }
        else if(option == 2)
            stack.show();
        else if(3){
            stack.pop();
        }
        else 
            cout << "\nOpção Invalida!!\n";
    }

    
    



    return 0;
}