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

int N, A, B;
ll v[50];

ll C(ll n, ll r){
	ll ret = 1;
	rep(i, r){
		ret *= n-i;
		ret /= (ll)i+1;
	}
	return ret;
}

signed main(){
	cin >> N >> A >> B;
	rep(i, N) cin >> v[i];
	sort(v, v+N);
	reverse(v, v+N);

	ll ave = 0;
	rep(i, A) ave += v[i];

	ll ans = 0;
	for(int i=A; i<=B; i++){
		ll sum = 0;
		rep(j, i) sum += v[j];
		if(ave*i == sum*A){
			int cnt = 0;
			int idx = i-1;
			rep(j, N){
				if(v[j] == v[i-1]){
					idx = min(idx, j);
					cnt++;
				}
			}
			ans += C(cnt, i-idx);
		}
	}
	cout << fixed << setprecision(16) << (double)ave/A << endl;
	cout << ans << endl;
}