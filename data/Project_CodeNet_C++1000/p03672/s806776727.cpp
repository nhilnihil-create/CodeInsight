#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める
bool is_es(string s){
    int n = s.length();
    if(n%2 == 1) return false;
    else{
        string s1 = s.substr(0,n/2);
        string s2 = s.substr(n/2);
        if(s1 == s2) return true;
        else return false;
    }
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int j = n-1;
    rep(i,n){
        s.erase(j,1);
        if(is_es(s)) {
            cout << s.length() << endl;
            return 0;
        }
        j--;
    }

    return 0;
}