#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n,keta = 0;
	vector<int> ans;
	cin >> n;
	int tmp = n + 1;
	while(tmp){
		tmp /= 2;
		keta++;
	}
	for(int i = 0;i < keta - 1;i++){
		if(((n + 1) >> i) & 1) ans.push_back(100 - i);
		ans.push_back(i + 1);
	}
	cout << ans.size() + 100 << endl;
	for(int i = 0;i < ans.size();i++) cout << (i ? " " : "") << ans[i];
	for(int i = 1;i <= 100;i++) cout << " " << i;
	cout << endl;
	return 0;
}