#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    if(A==B){
        cout << "Draw" << endl;
    }else if((B!=1&&A>B)||A==1){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
}