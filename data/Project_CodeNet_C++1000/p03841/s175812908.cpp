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
    ll N;
    cin >> N;
    ll x[510];
    rep(i,0,N) cin >> x[i];
    bool ok = true;
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back({x[i], i+1});
    }
    sort(lp.begin(), lp.end());
    ll res[500*500+10] = {};
    rep(i,0,N){
        ll num = lp[i].second;
        ll ps = lp[i].first;
        ll cnt = 0;
        rep(j,0,ps-1){
            if(res[j] == 0) cnt++;
        }
        if(cnt < num-1){
            ok = false;
            break;
        }
        ll n = num-1;
        ll idx = 0;
        while(n > 0){
            if(res[idx] == 0){
                res[idx] = num;
                idx++;
                n--;
            }else{
                idx++;
            }
        }
        res[ps-1] = num;
    }
    rrep(i,N-1,0){
        ll num = lp[i].second;
        ll ps = lp[i].first;
        ll cnt = 0;
        rrep(j,N*N-1,ps){
            if(res[j] == 0) cnt++;
        }
        if(cnt < N - num){
            ok = false;
            break;
        }
        ll n = N - num;
        ll idx = N*N-1;
        while(n > 0){
            if(res[idx] == 0){
                res[idx] = num;
                idx--;
                n--;
            }else{
                idx--;
            }
        }
    }
    if(ok){
        print("Yes");
        printa(res, N*N);
    }else{
        print("No");
    }

    

}
