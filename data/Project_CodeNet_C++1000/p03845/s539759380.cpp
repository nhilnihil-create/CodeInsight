#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, x;
	cin >> N;
	vector<int> qs;
	for(int i=0;i<N;i++){
		cin >> x;
		qs.push_back(x);
	}

	long long sum = accumulate(qs.begin(), qs.end(), 0);

	int M, y;
	vector<pair<int, int>> px;
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> x >> y;
		px.push_back({x,y});
	}

	int temp = sum;
	for(int i=0;i<M;i++){
		temp = sum;
		x = px[i].first;
		temp-=qs[x-1];
		temp+=px[i].second;
		cout << temp << "\n";
	}
	return 0;
}