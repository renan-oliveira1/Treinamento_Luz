#include <iostream>

using namespace std;

class Node{

    public:
        int value;
        Node* next;

        Node(int number){
            this->value = number;
            this->next = nullptr;
        }

};