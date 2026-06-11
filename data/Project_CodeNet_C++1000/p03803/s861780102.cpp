#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == 1 && b == 1) {
        cout << "Draw" << endl; 
        return 0;
    }else if(a == 1){
        cout << "Alice" << endl;
        return 0;
    }else if(b == 1){
        cout << "Bob" << endl;
        return 0;
    }

    if(a > b) cout << "Alice" << endl;
    else if(b > a) cout << "Bob" << endl;
    else cout << "Draw" << endl;



    return 0;
}