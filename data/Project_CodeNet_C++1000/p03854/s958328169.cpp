#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main(void){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string t = "";
    rep(i, s.size()){
        t += s[i];
        if(t == "maerd") t = "";
        else if(t == "remaerd") t = "";
        else if(t == "esare") t = "";
        else if(t == "resare") t = "";
    }
    if(t == "") cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}