#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string a,b;
    cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    if(na > nb){
        cout << "GREATER" << endl;
    }else if(na < nb){
        cout << "LESS" << endl;
    }else{
        rep(i,na){
            if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return 0;
            }else if(a[i] < b[i]){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    
    return 0;
}