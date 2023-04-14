#include <iostream>
#include"linked.cpp"

using namespace std;

class Stack{

    int top;

    int elements[100];
    LinkedList* list;
    public:
        Stack(){
            top = -1;
            list = new LinkedList();
        }

        void push(int value){
            list->insertEndNode(value);
        }

        void pop(){
            list->removeLast();
        }

        void show(){
            list->show();
        }


};