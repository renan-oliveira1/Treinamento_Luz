#include <iostream>

using namespace std;

class Node{

    public:
        int value;
        Node* next;
        Node(){}

        Node(int number){
            this->value = number;
            this->next = nullptr;
        }

        Node* operator+(Node& obj){
            this->next = &obj;
            return  this->next;
        }

};

class LinkedList{
    Node* head;
    int size;

    public:
        LinkedList(){head = NULL;size = 0;}

        void insertEndNode(int value){
            if(head == nullptr){
                head = new Node(value);
                return;
            }

            Node* newNode = new Node(value);
            Node* temp = head;

            while(temp->next!=nullptr){
                temp = temp->next;
            } 
            //temp = (*temp) + (*newNode);
            temp->next = newNode;
            this->size+=1;
        }

        void show(){
            Node* temp = head;
            cout << "\n";
            while(temp!=nullptr){
                cout << "  " << temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }

        void removeLast(){
            Node* temp = head;
            if(temp == nullptr){
                cout << "\nVazia!!\n";
                return;
            }

            if(temp->next == nullptr){
                head = NULL;
                return;
            }
            
            while(temp->next->next != nullptr){
                temp = temp->next;
            }

            Node* removeNode = temp->next;

            temp->next = nullptr;

            delete removeNode;
            
            cout << "\nElemento excluido!\n" << temp->value;

        }



        // void remove(int value){
        //     Node* temp = head;

        //     if(temp == nullptr){
        //         cout << "\nLista esta vazia!!\n";
        //         return;
        //     }
        //     Node* previous = nullptr;
        //     Node* toDelete = nullptr;

        //     while(temp != nullptr){
        //         if(temp->value == value)
        //             toDelete = temp;
        //             break;
        //         previous = temp;
        //         temp = temp->next;
        //     }

        //     if(toDelete == nullptr){
        //         cout << "\nElemento não encontrado!!\n";
        //     }else{
                
        //         if(previous == nullptr){
        //             head = temp->next;
        //             size = 0;

        //         }else{
        //             toDelete = temp;
        //             temp = temp->next;
        //             previous->next = temp;
        //         }
        //     }
            

        // }


};