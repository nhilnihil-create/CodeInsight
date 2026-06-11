#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

signed main(){
	int n,x[510],ans[510 * 510] = {};
	vector<P> vec;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i];
		vec.push_back(P(x[i] - 1,i));
		ans[x[i] - 1] = i + 1;
	}
	sort(vec.begin(),vec.end());
	int ind = 0;
	for(P p : vec){
		int num = p.second;
		while(num){
			if(!ans[ind]){
				ans[ind] = p.second + 1;
				num--;
			}
			ind++;
		}
	}
	ind = n * n - 1;
	for(int i = 0;i < n;i++){
		P p = vec[n - 1 - i];
		int num = n - p.second - 1;
		while(num){
			if(!ans[ind]){
				ans[ind] = p.second + 1;
				num--;
			}
			ind--;
		}
	}
	for(int i = 0;i < n;i++){
		int cnt = 0;
		for(int j = 0;j < x[i];j++) if(ans[j] == i + 1) cnt++;
		if(cnt != i + 1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for(int i = 0;i < n * n;i++) cout << (i ? " " : "") << ans[i];
	cout << endl;
}