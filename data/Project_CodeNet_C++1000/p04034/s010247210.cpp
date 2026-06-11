#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n,m;
	cin >> n >> m;
	vector<pair<bool,int>> box(n);
	box[0].first = true;
	box[0].second = 1;
	for(int i=1;i<n;i++){
		box[i].first = false;
		box[i].second = 1;
	}
	rep(i,m){
		int x,y;
		cin >> x >> y;
		x--;y--;
		if(box[x].first==true)
			box[y].first = true;
		box[y].second++;
		box[x].second--;
		if(box[x].second == 0)
			box[x].first = false;
	}
	int cnt=0;
	rep(i,n){
		if(box[i].first == true)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}

