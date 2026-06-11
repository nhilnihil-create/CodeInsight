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

ll n, d[301][301], e[301][301], ans;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ll a;
			cin >> a;
			d[i][j] = a;
			e[i][j] = a;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			} 
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			} 
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]<e[i][j]){
				cout << 0-1 << endl;
				return 0;
			} 
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool f = 0;
			for(int k=0;k<n;k++){
				if((i-k)*(k-j)*(j-i)!=0 && d[i][j] == d[i][k]+d[k][j]){
					f = 1;
				}
			} 
			if(!f) ans += d[i][j];
		}
	}

	cout << ans/2 << endl;
	return 0;
}