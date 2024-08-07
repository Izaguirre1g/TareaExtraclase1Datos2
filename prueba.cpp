#include <iostream>
using namespace std;
int main(){
    int myNum[3] = {10, 20, 30};
    int *ptr;
    int *ptr1;

    ptr = myNum;
    ptr1 = (myNum+1);
    cout << &(myNum) << endl;
    cout << &ptr1 << endl;
    cout << *ptr << endl;
}

