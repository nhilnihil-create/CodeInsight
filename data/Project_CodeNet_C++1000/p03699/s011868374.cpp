#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int total = 0;
	int s[N];
	rep(i,N) {
		cin >> s[i];
		total += s[i];
	}
	sort(s,s+N);
	if (total%10 != 0) {
		cout << total << endl;
		return 0;
	}

	rep(i,N) {
		if (s[i]%10 == 0) continue;
		total -= s[i];
		cout << total << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
