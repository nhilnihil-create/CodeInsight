#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define gt first
#define gc second.first
#define gr second.second
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int main(void){
	int n,i,j,k;
	ll a[334][334],b[334][334],ans=0ll;
	bool flag = true,d[334][334];
	fill(d[0],d[334],true);
	cin >> n;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for(k=0; k<n; ++k){
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				b[i][j] = min(b[i][j],b[i][k] + b[k][j]);
			}
		}
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(a[i][j] != b[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	if(!flag){
		cout << -1 << endl;
		return 0;
	}
	for(k=0; k<n; ++k){
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				if(i == k || k == j){
					continue;
				}
				if(a[i][j] == a[i][k] + a[k][j]){
					d[i][j] = false;
				}
			}
		}
	}
	for(i=0; i<n; ++i){
		for(j=i; j<n; ++j){
			if(d[i][j]){
				ans += a[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
