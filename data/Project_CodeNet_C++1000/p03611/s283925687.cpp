#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int cnt[100100] = {};
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		if(a > 0) cnt[a-1]++;
		cnt[a]++;
		cnt[a+1]++;
	}
	cout << *max_element(cnt, cnt + 100100) << endl;;
	cout << endl;

}
