// failed to generate code

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
// #define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

#define MAX_N 301
#define INF 10000000000001
bool d[MAX_N][MAX_N];


// void warshall_floyd() {
// 	for (int k = 0; k < N; k++) 
// 		for (int i = 0; i < N; i++) 
// 			for (int j = 0; j < N; j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
// }


int main(){	
	ll N;
	cin >> N;
	vector< vector<ll> > A(N, vector<ll>(N));
	rep(i, N) {
		rep(j, N) {
			cin >> A[i][j];
		}
	}
	rep(k, N) {
		rep(i, N) {
			rep(j, N) {
				if (i == j || i == k || j == k) continue;
				if (A[i][j] > A[i][k]+A[k][j]) {
					// cout << i << " " << j << " " << k << endl;
					// cout << A[i][j] << " " << A[i][k] << " " << A[k][j] << endl;
					cout << "-1" << endl;
					return 0;
				} else if (A[i][j] == A[i][k]+A[k][j]) {
					d[i][j] = true;
					d[j][i] = true;
				}
			}
		}
	}
	ll res = 0;
	rep(i, N) {
		rep(j, N) {
			if (!d[i][j]) res += A[i][j];
		}
	}
	cout << res/2 << endl;
	return 0;
}
