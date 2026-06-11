#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)

int n, L, T;
int x[100010], w[100010];

int main(void){
	cin>>n>>L>>T;
	for (int i = 0; i < n; i++) cin>>x[i]>>w[i];

	vector<ll> tmp(n);
	for (int i = 0; i < n; i++) {
		if (w[i] == 1) tmp[i] = (x[i] + T) % L;
		else tmp[i] = ((x[i] - T) % L + L) % L;
	}

	sort(tmp.begin(), tmp.end());

	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (w[i] == 1) cnt -= (T - (L - x[i]) + L) / L;
		else cnt += (T - (x[i] + 1) + L) / L;
	}
	cnt = (cnt % n + n) % n;
	vector<ll> res(n);

	for (int i = 0; i < n; i++) res[(i + cnt) % n] = tmp[i];
	for (int i = 0; i < n; i++) cout<< res[i] <<endl;

	
	return 0;
}