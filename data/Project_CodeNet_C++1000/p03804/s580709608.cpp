#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
#define dup(x,y) (((x)+(y)-1)/(y)) // x/yの除算の切り上げ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007; //1000000007
const ld pi = acos(-1);
 
//xor演算
//a^b=b^a
//a^(b^c)=(a^b)^c
//a^a=0
//a+b=a^b + 2(a&b)
//(4a)^(4a+1)^(4a+2)^(4a+3)=0
 
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }
    ll ans=0;
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){
            ll x=0;
            rep(k,m){
                if(b[k]==a[j+k].substr(i,m)){
                    x++;
                }
                else{
                    break;
                }
            }
            if(x==m){
                ans=1;
                break;
            }
        }
        if(ans==1) break;
    }
    if(ans==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}