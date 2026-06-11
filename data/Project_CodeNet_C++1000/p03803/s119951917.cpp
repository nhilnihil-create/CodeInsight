#include <bits/stdc++.h>
using namespace std;

int Bob, Alice, Draw, x ,y;

int main () {
    cin >> x >> y;
    if (x==y){
        cout << "Draw" << endl;
    }else if (y==1){
        cout << "Bob" << endl;
    }else if ((x>y)||(x==1)){
        cout << "Alice" << endl;
    }else if (x==1){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
}
}
