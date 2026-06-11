#include <iostream>
using namespace std;

int main() {
    string stra;
    int x;
    bool r=true;
    cin >> stra;
    x= stra.length();
    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            if(stra[i]==stra[j]){
                r=false;
                break;
            }
        }
    }
    if(r==false){
        cout << "no" << endl;
    }else if(r==true){
        cout << "yes" << endl;
    }
}