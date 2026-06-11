#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ans[50];
ll a[50][2], dis[50], x, y;

ll manhattan(ll x1, ll y1, ll x2, ll y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main() {
	cin >> n >> m;

	for(int i=0; i<n; i++){
		cin >> a[i][0] >> a[i][1];
		dis[i] = 2e9;
		ans[i] = 60;
	}

	for(int i=0; i<m; i++){
		cin >> x >> y;
		for(int j=0, tempdis; j<n; j++){
			tempdis = manhattan(a[j][0], a[j][1], x, y);
			if(tempdis < dis[j]){
				dis[j] = tempdis;
				ans[j] = i+1;
			}
		}
	}

	for(int i=0; i<n; i++){
		cout << ans[i] << endl;
	}
}