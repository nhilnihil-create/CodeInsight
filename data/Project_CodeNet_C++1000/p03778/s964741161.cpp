#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, a, b; cin >> w >> a >> b;
    if (a==b){
        cout << 0 << endl;
    } else if (a<b){
        if (b<=a+w){
            cout << 0 << endl;
        } else {
            cout << b-(a+w) << endl;
        }
    } else {
        if (a<=b+w){
            cout << 0 << endl;
        } else {
            cout << a-(b+w) << endl;
        }
    }
}