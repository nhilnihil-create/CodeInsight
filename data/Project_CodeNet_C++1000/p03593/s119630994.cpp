#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
constexpr ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i,H)cin >> S[i];
    map<char,int> m;
    REP(i,H){
        REP(l,W){
            m[S[i][l]]++;
        }
    }
    bool ok = 1;
    if((H%2) + (W%2) == 0){
        for(auto itr = m.begin();itr != m.end();itr++){
            if((itr->S) %4 != 0)ok = 0;
        }
    }else if((H%2) + (W%2) == 1){
        ll a2 = 0;
        for(auto itr = m.begin();itr != m.end();itr++){
            if((itr->S) %4 == 2){
                a2++;
            }else if((itr->S) %4 != 0)ok = 0;
        }
        if(W % 2 == 1){
            if(a2 > H/2)ok = 0;
        }else{
            if(a2 > W/2)ok = 0;
        }
    }else{
        ll a2 = 0;
        ll a1 = 0;
        for(auto itr = m.begin();itr != m.end();itr++){
            if((itr->S) %4 == 2){
                a2++;
            }else if((itr->S) %4 == 1){
                a1++;
            }else if((itr->S) %4 == 3){
                a2++;
            }
        }
        if(a1 > 1)ok = 0;
        if((H+W-1)/2 < a2)ok = 0;
    }
    cout << (ok ? "Yes" : "No") << "\n";
}