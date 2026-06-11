#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
ll a[300000];
set<pair<ll,int>> A, B, Bl;
ll Asum = 0, Bsum = 0;

signed main(){
    cin >> N;
    rep(i, 3*N){
        cin >> a[i];
        if(i < N){
            Asum += a[i];
            A.insert({ a[i],i });
        }
        else B.insert({ a[i],i });
    }

    auto itr = B.begin();
    rep(j, N){
        Bsum += itr->first;
        itr++;
    }
    rep(j, N){
        Bl.insert(*prev(B.end()));
        B.erase(prev(B.end()));
    }

    ll ans = Asum - Bsum;
    rep(i, N){
        Asum += a[N+i];
        A.insert({ a[N+i], N+i });
        Asum -= A.begin()->first;
        A.erase(A.begin());
        if(Bl.count({ a[N+i], N+i })){
            Bl.erase({ a[N+i], N+i });
        }
        else{
            Bsum -= a[N+i];
            B.erase({ a[N+i],N+i });
            Bsum += Bl.begin()->first;
            B.insert(*Bl.begin());
            Bl.erase(Bl.begin());
        }
        ans = max(ans, Asum-Bsum);
    }
    cout << ans << endl;
}