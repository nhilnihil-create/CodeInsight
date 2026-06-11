#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	auto dist = [&](int src, int dst){
		if(src <= dst) return dst - src;
		return dst + m - src;
	};
	while(cin >> n >> m){
		vector<int> a(n);
		for(int& t : a){ cin >> t; --t; }
		vector<int> dif(m, 0);
		vector<int> add(m, 0);
		for(int i=0;i<n-1;i++) dif[(a[i]+1)%m]++;
		for(int i=1;i<n;i++){
			dif[a[i]]--;
			add[a[i]] += dist(a[i-1], a[i]) - 1;
		}
		int cnt = dif[0];
		long long cur = 0;
		for(int i=0;i+1<n;i++){
			int distA = dist(a[i], a[i+1]);
			int distB = dist(0, a[i+1]) + 1;
			if(distB < distA) ++cnt;
			cur += min(distA, distB);
		}
		long long res = cur;
		for(int i=1;i<m;i++){
			cur -= cnt;
			cur += add[(i+m-1)%m];
			cnt += dif[i];
			res = min(cur, res);
		}
		cout << res << endl;
	}
}
