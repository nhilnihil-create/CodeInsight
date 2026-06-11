#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		cnt[val]++;
	}
	int num[2] = {0, 0};
	for(auto &i : cnt) num[i.second % 2]++;
	if(num[0] % 2 == 1) cout << (int)cnt.size() - 1 << '\n';
	else cout << (int)cnt.size() << '\n';
	return 0;
}