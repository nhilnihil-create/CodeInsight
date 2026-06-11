#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using Um = unordered_map<char,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

vector<long long> divisor(long long n) {
vector<long long> ret;
for (long long i = 1; i * i <= n; ++i) {
if (n % i == 0) {
ret.push_back(i);
if (i * i != n) ret.push_back(n / i);
}
}
sort(ret.begin(), ret.end()); // 昇順に並べる
return ret;
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    Um um;
    for(ll i=0;i<H;++i)
        for(ll j=0;j<W;++j){
            char c;cin>>c;um[c]++;
        }
    if(H%2==0&&W%2==0){
        bool ok=1;
        for(auto p: um){
            if(p.second%4!=0){
                ok=0;break;
            }
        }
        if(ok){
            prt("Yes");
        }
        else prt("No");
    }
    else if(H%2==1&&W%2==0){
        vector<ll> vec(4,0);
        for(auto p: um){
            vec[p.second%4]++;
        }
        if(vec[1]==0&&vec[3]==0&&vec[2]<=W/2){
            prt("Yes");
        }
        else prt("No");
    }
    else if(H%2==0&&W%2==1){
        vector<ll> vec(4,0);
        for(auto p: um){
            vec[p.second%4]++;
        }
        if(vec[1]==0&&vec[3]==0&&vec[2]<=H/2){
            prt("Yes");
        }
        else prt("No");
    }
    else {
        vector<ll> vec(4,0);
        for(auto p: um){
            vec[p.second%4]++;
        }
        if(vec[1]+vec[3]==1&&vec[2]+vec[3]<=(H+W-2)/2){
            prt("Yes");
        }
        else prt("No");
    }
    

    return 0;
}

