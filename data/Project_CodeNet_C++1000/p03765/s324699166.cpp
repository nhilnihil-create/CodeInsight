/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;
    ll ss[100010] = {}, tt[100010] = {};
    rep(i,0,S.size()){
        if(S[i] == 'A'){
            ss[i+1] = 2;
        }else{
            ss[i+1] = 1;
        }
    }
    rep(i,0,T.size()){
        if(T[i] == 'A'){
            tt[i+1] = 2;
        }else{
            tt[i+1] = 1;
        }
    }
    rep(i,0,S.size()+1) ss[i+1] += ss[i];
    rep(i,0,T.size()+1) tt[i+1] += tt[i];
    ll q;
    cin >> q;
    while(q--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if((ss[b+1] - ss[a]) % 3 == (tt[d+1] - tt[c]) % 3){
            print("YES");
        }else{
            print("NO");
        }
    }
    

}