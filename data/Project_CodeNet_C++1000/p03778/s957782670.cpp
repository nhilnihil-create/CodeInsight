
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int w, a, b;
    cin >> w >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    else if (b > a){
        if (b <= a + w){
            cout << 0 << endl;
            return 0;
        }
        else{
            cout << b - a - w << endl;
            return 0;
        }
    }
    else{
        if (a <= b + w){
            cout << 0 << endl;
            return 0;
        }
        else{
            cout << a - b - w << endl;
        }
    }
    
}