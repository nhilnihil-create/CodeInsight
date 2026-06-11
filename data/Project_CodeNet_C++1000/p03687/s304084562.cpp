#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll dfs(string S, ll cnt, char c){
    bool stp = true;
    rep(i,S.size()){
        if(S[i] != c){
            stp = false;
            break;
        }
    }
    if(stp){
        return cnt;
    }
    string T = S;
    rep(i,S.size()-1){
        if(S[i] == c || S[i+1] == c){
            T[i] = c;
        }
    }
    return dfs(T.substr(0,T.size()-1), ++cnt, c);
}

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    map<char,ll> mp;
    rep(i,N){
        mp[S[i]]++;
    }
    ll ans = 1e18;
    for(auto& e:mp){
        cmin(ans, dfs(S, 0, e.first));
    }
    cout << ans << endl;
}
