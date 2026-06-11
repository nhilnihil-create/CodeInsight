#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

ll func(string s, char ch){
    ll N = s.size();
    bool f = true;
    rep(i,N){
        if(s[i] != ch)f=false;
    }
    if(f) return 0;
    string t(N-1, ch+1);
    rep(i,N-1){
        if(s[i] == ch || s[i+1] == ch){
            t[i] = ch;
        }else{
            t[i] = ch+1;
        }
    }
    return 1+func(t,ch);
}

int main(){
    string s;
    cin >> s;
    ll m = 1e10;    
    rep(i,26){
        m = min(m, func(s,'a'+i));
    }
    cout << m << endl;
}
