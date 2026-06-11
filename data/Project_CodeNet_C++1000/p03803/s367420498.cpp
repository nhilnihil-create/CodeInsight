#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b ;
    if (a==1){
        a+=1234;
    }
    if (b==1){
        b+=1234;
    }
    if(a>b){
        cout << "Alice";
    }else if (a<b){
        cout << "Bob";
    }else{
        cout << "Draw";
    }
    return 0;
}