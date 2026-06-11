#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll x; cin>>x;
    ll res=0;
    res+=2*(x/11);
    x%=11;
    if(x>6) res+=2;
    else if(x>0) res++;
    cout<<res<<endl;
}