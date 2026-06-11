#include <bits/stdc++.h>
using namespace std;


int main() {
    int W, a, b;
    cin >> W >> a >> b;

    if(a <= b){
        if(a+W < b){
            cout << b - a - W << endl;
            return 0;
        }else{
            cout << 0 << endl;
        }
    }else{
        if(b+W < a){
            cout << a - b - W << endl;
            return 0;
        }else{
            cout << 0 << endl;
        }
    }

}