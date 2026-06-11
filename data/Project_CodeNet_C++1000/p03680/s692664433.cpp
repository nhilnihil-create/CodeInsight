#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, ans = 0;
	vector<int> a;
	vector<bool> check;	// i番目のボタンを押したかどうか
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp_a;
		cin >> tmp_a;
		a.push_back(tmp_a);
		check.push_back(false);
	}
	
	int idx = 0;	// 次に光るボタンの番号
	while(!check[idx]){
		if(idx == -1)	idx = 0;
		ans++;
		check[idx] = true;
		idx = a[idx] - 1;
		if(idx == 1){
			cout << ans << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}