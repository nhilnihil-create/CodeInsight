#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

map<ld,Pll> mp;

ll a,b,c,d,e,f;
/*
ld dfs(ll wa, ll su){
    if(wa*100 + su > f) return 0;
    ld res = ld(ld(su)/ld(wa*100+su)); 
    mp[res] = Pll(wa,su);
    if(wa*e >= su+c){
        cmax(res, dfs(wa, su+c));
    }
    if(wa*e >= su+d){
        cmax(res, dfs(wa, su+d));
    }
    cmax(res, dfs(wa+a,su));
    cmax(res, dfs(wa+b,su));
    return res;
}*/

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    //a *= 100;
    //b *= 100;
    //ld M = max(dfs(a,0), dfs(b,0));
    //cout << M << endl;
    vector<ll> dw(31), ds(1501);
    REP(i,1,31){
        if(i*a < 31){
            dw[i*a]++;
        }
    }
    dw[0] = 1;
    rep(i,31){
        if(dw[i]>0){
            if(i+b<31){
                dw[i+b]++;
            }
        }
    }
    REP(i,1,1501){
        if(i*c < 1501){
            ds[i*c]++;
        }
    }
    ds[0] = 1;
    rep(i,1501){
        if(ds[i]>0){
            if(i+d<1501){
                ds[i+d]++;
            }
        }
    }
    ld M = 0;
    REP(i,1,31){
        if(dw[i] > 0){
            ll tmp = 0;
            if(i*100 > f){
                break;
            }
            for(ll j=0;j<1501;j++){
                if(i*100+j > f) break;
                if(i*e < j) break;
                if(ds[j] == 0) continue;
                tmp = j;
            }
            if(tmp > 0){
                cmax(M, ld(tmp)/ld(i*100+tmp));
                mp[ld(tmp)/ld(i*100+tmp)] = Pll(i,tmp);
            }
        }
    }
    if(M==0){
        cout << a*100 << " "<< 0 << endl;
        return 0;
    }
    cout << mp[M].first*100 + mp[M].second << " " << mp[M].second << endl;
}