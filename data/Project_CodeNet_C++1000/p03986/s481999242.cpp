#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

stack<char> p;
ll s[210000],t[210000];
int main(){
    ll ans=0;
    string x;
    cin>>x;
    rep(i,0,x.size()){
        if(x[i]=='S')p.push('S');
        else{
            if(p.size()==0||p.top()=='T')p.push('T');
            else p.pop();
        }
    }
    cout<<p.size();

}
