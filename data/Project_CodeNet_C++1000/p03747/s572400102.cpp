#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	long long L, T;
	while(cin >> N >> L >> T){
		L *= 2;
		T *= 2;
		vector<pair<long long, int>> X(N);
		for(auto& p : X){
			cin >> p.first >> p.second;
			p.first *= 2;
			p.second = (p.second == 1 ? 1 : -1);
		}
		long long add = 0;
		for(int i=0;i<N;i++){
			if(X[i].second == X[0].second) continue;
			long long pos0 = X[0].first;
			long long pos1 = X[i].first;
			if(X[0].second == -1) swap(pos0, pos1);
			if(pos1 < pos0) pos1 += L;
			long long first = (pos1 - pos0)/2;
			if(T < first) continue;
			long long rest = T - first;
			add++;
			add += rest/(L/2);
		}
		long long endPos = (X[0].first + L + T%L * X[0].second) % L;
		vector<pair<long long, long long>> vp;
		for(auto p : X){
			vp.emplace_back((p.first + L + T%L * p.second) % L, p.second);
		}
		sort(vp.begin(), vp.end());
		int start = -1;
		for(int i=0;i<vp.size();i++){
			if(vp[i].first == endPos && vp[i].second == X[0].second) start = i;
		}
		start = (start + N - add%N * X[0].second) % N;
		for(int i=0;i<vp.size();i++){
			cout << vp[(i+start)%vp.size()].first/2 << endl;
		}
	}
}
