#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    if(a == 1 && b == 1){
        cout << "Draw" << endl;
        exit(0);
    }else if(b == 1){
        cout << "Bob" << endl;
        exit(0);
    }else if(a == 1){
        cout << "Alice" << endl;
        exit(0);
    }
    
    if(a > b){
        cout << "Alice" << endl;
    }else if(a < b){
        cout << "Bob" << endl;
    }else{
        cout << "Draw" << endl;
    }
}
