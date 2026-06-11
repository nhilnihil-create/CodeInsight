#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int ncr(int n, int r){
	if(r < 0 || n < r) return 0;
	if(r == 0) return 1;
	return n * ncr(n-1, r-1) / r;
}

signed main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);

	for(int i = 0;i < n;i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	double ans = v[0];
	int cnt = 1;
	int start = 0; 
	for(int i = 1;i < n;i++){
		if(i < a) ans += v[i];
		if(v[i-1] != v[i]){
			if(i < a){
				start = i;
				cnt = 1;
			}else{
				break;
			}
		}else{
			cnt++;
		}
	}

	int ans_cnt = 0;
	if(start == 0){
		for(int i = a;i <= b;i++){
			ans_cnt += ncr(cnt, i-start);
		}
	}else{
		ans_cnt += ncr(cnt, a-start);
	}

	printf("%.12lf\n", ans/(double)a);
	cout << ans_cnt << endl;

	return 0;
}
