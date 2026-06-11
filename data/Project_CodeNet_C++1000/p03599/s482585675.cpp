#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
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
    ll A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<ll> water(0);
    REPS(i,F){
        REP(l,i+1){
            if(100*A*l + 100*B*(i-l) <= F){
                water.pb(A*l+B*(i-l));
            }
        }
    }
    sort(ALL(water));
    UNIQUE(water);
    vector<ll> sugar(0);
    REPS(i,F){
        REP(l,i+1){
            if(C*l + D*(i-l) <= F){
                sugar.pb(C*l+D*(i-l));
            }
        }
    }
    sort(ALL(sugar));
    UNIQUE(sugar);
    ll satou = -1;
    ll mizu = -1;
    ll mitsudoa = -1;
    ll mitsudob = 100;
    REP(i,water.size()){
        ll up = min(E * water[i],F - 100 * water[i]);
        ll num = upper_bound(ALL(sugar),up) - sugar.begin();
        num--;
        if(num >= 0){
            if(mitsudoa*(water[i] + sugar[num]) < 100*sugar[num]*mitsudob){
                mitsudoa = 100*sugar[num];
                mitsudob = (water[i] + sugar[num]);
                satou = sugar[num];
                mizu = sugar[num] + water[i]*100;
            }
        }else{
            if(mitsudoa*water[i] < 0){
                mitsudoa = 0;
                mitsudob = water[i];
                satou = 0;
                mizu = water[i]*100;
            }
        }
    }
    cout << mizu << " " << satou << "\n";
}