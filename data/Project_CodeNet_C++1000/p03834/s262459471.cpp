#include <iostream>
using namespace std;

int main() {
    string stra;
    cin >> stra;
    for(int i=0;i<5;i++){
        cout << stra[i];
    }
    cout << " ";
    for(int i=6;i<13;i++){
        cout << stra[i];
    }
    cout << " ";
    for(int i=14;i<=18;i++){
        cout << stra[i];
    }
    cout << endl;

}