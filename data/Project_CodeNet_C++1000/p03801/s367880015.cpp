#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int N;
	cin >> N;
	vector<int> a(N), res(N);
	priority_queue<pair<int,int>> Q;
	Q.push(make_pair(0,0));
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
		Q.push(make_pair(a[i], N - i));
	}
	int idx = Q.top().second, t = Q.top().first, cnt = 1;
	Q.pop();
	while(!Q.empty()) {
		//cout << idx << "," << cnt << "," << t << endl;
				//cout << ">" << Q.top().first << "," << Q.top().second << endl;
		if(idx >= Q.top().second) {
			if (Q.top().first >= t) {
				res[N - idx] += Q.top().first - t;
				++cnt;
				Q.pop();
			} else {
				// cout << ">" << Q.top().first << "," << Q.top().second << endl;
				res[N - idx] += (t - Q.top().first) * cnt;
				t = Q.top().first;
				++cnt;
				Q.pop();
			}
		} else {
			// cout << "|" << Q.top().first << "," << Q.top().second << endl;
			res[N - idx] += (t - Q.top().first) * cnt;
			t = Q.top().first;
			++cnt;
			idx = Q.top().second;
			Q.pop();
		}
	}
	for(int i = 0; i < N; ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
