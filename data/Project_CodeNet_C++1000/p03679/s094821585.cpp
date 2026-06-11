#include<bits/stdc++.h>
// sakib malik
using namespace std;

int main(){
    int x , a, b;
    cin >> x >> a >> b;
    int t = b - a;
    if(b <= a){
        cout << "delicious";
    }
    else if(b - a<= x){
        cout << "safe";
    }
    else {
        cout << "dangerous";
    }

}