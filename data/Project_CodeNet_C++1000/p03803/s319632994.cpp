#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    string s;
    cin >> a >> b;
    if (a == 1){
        a += 13;
    }
    if (b == 1){
        b += 13;
    }
    if (a == b){
        s = "Draw";
    }else if (a < b){
        s = "Bob";
    }else{
        s = "Alice";
    }
    cout << s << endl;
}