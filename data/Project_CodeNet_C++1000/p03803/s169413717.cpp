#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << "Draw";
        return 0;
    }

    if(a == 1){
        cout << "Alice";
        return 0;
    }else if(b == 1){
        cout << "Bob";
        return 0;
    }
    a>b?cout<<"Alice":cout<<"Bob";
    return 0;
}