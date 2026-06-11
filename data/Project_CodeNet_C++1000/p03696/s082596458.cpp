#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n; string s;
    cin >> n >> s;
    ll l = 0, r = 0;
    rep(i, n){
        if(s[i] == '(') l++;
        else{
            if(l > 0) l--;
            else r++;
        }
    }
    string ans = "";
    
    rep(i, r) ans += '(';
    ans += s;
    rep(i, l) ans += ')';

    cout << ans << endl;
    return 0;
}