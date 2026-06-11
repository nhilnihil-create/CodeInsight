#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> p(N);
	for(int i = 0; i < N; ++i) {
		cin >> p[i];
		--p[i];
	}
	int cnt = 0;
	for(int i = 0; i < N - 1; ++i) {
		if(p[i] == i) {
			swap(p[i], p[i + 1]);
			++cnt;
		}
	}
	if(p[N-1] == N - 1) {
		swap(p[N-1], p[N-2]);
		++cnt;
	}
	cout << cnt << endl;
	return 0;
}
