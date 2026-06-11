#include <iostream>
using namespace std;

int main() {
    string stra;
    int x;
    bool r=false;
    cin >> stra;
    for(int i=97;i<=122;i++){
        if(stra.find((char)i)==-1){
            cout << (char)i << endl;
            r=true;
            break;
        }
    }
    if(r==false){
        cout << "None" << endl;
    }
}