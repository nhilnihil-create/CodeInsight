//ARC071D
#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define INF 999999999
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};

ll n, m, sx[100010], sy[100010], sumx, sumy;

int main(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> sx[i];
	}
	for(ll i=1;i<=m;i++){
		cin >> sy[i];
	}
	for(ll i=1;i<=n-1;i++){
		sumx = (sumx + i*(n-i)*(sx[i+1]-sx[i])) % MOD;
	}
	for(ll i=1;i<=m-1;i++){
		sumy = (sumy + i*(m-i)*(sy[i+1]-sy[i])) % MOD;
	}
	cout << (sumx+MOD)*(sumy+MOD)%MOD << endl;
	return 0;
}