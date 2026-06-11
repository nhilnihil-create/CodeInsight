#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
	vector<pair<int, int>> a;
	for(int i=0; i<N; i++){
		int b; cin >> b;
		a.push_back({b, -i-1});
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>() );
	long long ans[N+1];
	fill(ans, ans+N+1, 0);
	long long sum = a[0].first, prev = 0;
	int now = -a[0].second;
	for(int i=1; i<N; i++){
		if(-a[i].second < now){
			ans[now] = sum - (long long)a[i].first * i - prev;
			prev += ans[now];
			now = (-a[i].second);
		}
		sum += a[i].first;
	}
	ans[now] = sum - prev;
	for(int i=0; i<N; i++){
		cout << ans[i+1] << endl;
	}
	return 0;
}