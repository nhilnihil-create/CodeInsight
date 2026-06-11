#include <iostream>
using namespace std;

int main() {
    string stra;
    int x;
    cin >> stra;
    x= stra.length();
    for(int i=0;i<x;i++){
        int j=i+1;
        if(j%2!=0){
            cout << stra[i];
        }
    }
    cout << endl;
}