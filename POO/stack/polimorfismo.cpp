#include <iostream>

using namespace std;

class Testing{
    private:
        int number;

    public:
        Testing(int number1){
            number = number1;
        }

        //lincar os nós
        int operator+(Testing& obj){
            string str = std::to_string(number);
            string str2 = std::to_string(obj.number);
            string finalString =  str + str2;
            return (int) stoi(finalString);
        }

};

int main(){
    Testing n1(2);
    Testing n2(12);

    int sum = n1 + n2;

    cout << sum;


    return 0;
}
