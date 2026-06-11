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
stack<ll> st[100010];
ll cnt2[100010] = {};
vector<ll> atode[100010];
ll cnt[100010] = {};
ll X[100010];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,N) cin >> X[i];
    vector<ll> val[100010];
    rep(i,0,N) val[X[i] % M].push_back(X[i]);
    ll ans = 0;
    rep(i,0,M/2+1){
        if(i == 0){
            ans += val[i].size() / 2;
        }else if(M % 2 == 0 && i == M/2){
            ans += val[i].size() / 2;
        }else{
            ll j = M - i;
            ans += min(val[i].size(), val[j].size());
            if(val[i].size() > val[j].size()){
                ll diff = val[i].size() - val[j].size();
                map<ll,ll> mp;
                ll cnt = 0;
                rep(k,0,val[i].size()){
                    mp[val[i][k]]++;
                    if(mp[val[i][k]] % 2 == 0){
                        cnt++;
                    }
                }
                ans += min(cnt, diff/2);

            }else{
                ll diff = val[j].size() - val[i].size();
                map<ll,ll> mp;
                ll cnt = 0;
                rep(k,0,val[j].size()){
                    mp[val[j][k]]++;
                    if(mp[val[j][k]] % 2 == 0){
                        cnt++;
                    }
                }
                ans += min(cnt, diff/2);         
            }

        }

    }
    print(ans);
}