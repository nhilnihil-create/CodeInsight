#include <bits/stdc++.h>
using namespace std;
int N;vector< pair<int, int> > vec;vector<int> dust;
int cnt[505];int ans[250005];
int main(void){
	cin >> N;
	int x;
	for(int i = 1; i <= N; i++){cin >> x;vec.push_back( make_pair(x, i) );}
	sort(vec.begin(), vec.end());
	int nid = 0, tid = 0, set;
	for(int i = 1; i <= N*N; i++){
		if(nid < vec.size() && i >= vec[nid].first){
			if(cnt[vec[nid].second] < vec[nid].second-1){
				cout << "No" << endl;
				return 0;
			}
			ans[i] = vec[nid].second;
			cnt[vec[nid].second]++;
			for(int j = 0; j < N - vec[nid].second; j++) dust.push_back(vec[nid].second); 
			nid++;
			continue;
		}
		while(tid < vec.size() &&cnt[vec[tid].second] >= vec[tid].second-1) tid++;
		if(tid >= vec.size()){
			if(dust.size() == 0){
				cout << "No" << endl;
				return 0;
			}
			set = dust.back();
			dust.pop_back();
		}
		else set = vec[tid].second;
		ans[i] = set;
		cnt[set]++;
	}
	cout << "Yes" << endl;
	for(int i = 1; i <= N*N; i++){
		cout << ans[i];
		if(i != N*N) cout << " ";
	}
	cout << endl;
	return 0;
}