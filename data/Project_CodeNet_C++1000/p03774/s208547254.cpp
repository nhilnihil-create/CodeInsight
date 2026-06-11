#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 1e9;

int calDist(int x1, int y1, int x2, int y2){
	return (abs(x1-x2) + abs(y1-y2));
}

int main(){
	int n, m; 
	cin >> n >> m;
	vector<pair<int,int>> i1(n), i2(m);
	for(int i = 0; i < n; ++i)
		cin >> i1[i].first >> i1[i].second;
	for(int i = 0; i < m; ++i)
		cin >> i2[i].first >> i2[i].second;
	for(int i = 0; i < n; ++i){
		pair<int, int> best = {0, INF};
		for(int j = 0; j<m; ++j){
			int cur = calDist(i1[i].first, i1[i].second, i2[j].first, i2[j].second);
			if(cur < best.second){
				best.second = cur;
				best.first = j;
			}
		}
		cout << best.first + 1  << "\n";
	}
	return 0;
}
