#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int ans[250010], used[250010];

int main(){
	int N; cin >> N;
	vector<P> x;
	vector<int> arr;
	for(int i=0; i<N; i++){
		int xx; cin >> xx;
		x.push_back(P(xx, i+1));
		ans[xx] = i + 1;
		used[xx] = 1;
	}
	for(int i=1; i<=N*N; i++){
		if(used[i] == 0) arr.push_back(i);
	}
	sort(x.begin(), x.end());
	int cnt = 0, f = 0;
	for(int i=0; i<N; i++){
		cnt += x[i].second;
		if(cnt > x[i].first) f = 1;
	}
	cnt = 0;
	for(int i=N-1; i>=0; i--){
		cnt += N + 1 - x[i].second;
		if(cnt > N*N + 1 - x[i].first) f = 1;
	}
	if(f) cout << "No" << "\n";
	else{
		cout << "Yes" << "\n";
		int now = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<x[i].second - 1; j++){
				ans[arr[now]] = x[i].second;
				now++;
			}
		}
		now = N*N - N - 1;
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<N - x[i].second; j++){
				ans[arr[now]] = x[i].second;
				now--;
			}
		}
		for(int i=1; i<=N*N; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}