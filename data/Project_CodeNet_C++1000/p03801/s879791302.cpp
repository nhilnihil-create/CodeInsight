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
pair<ll, ll> v[100001];
ll ans[100000] ={};

signed main(){
    cin >> N;
    rep(i, N){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v, v+N);
    reverse(v, v+N);
    v[N].first = 0;

    ll m = INT_MAX;
    rep(i, N){
        m = min(m, v[i].second);
        ans[m] += (v[i].first-v[i+1].first)*(i+1);
    }
    rep(i, N) cout << ans[i] << endl;
}