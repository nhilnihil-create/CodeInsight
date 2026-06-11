#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	deque<int> que;
	for(int i = 0; i < n; i++)
		if(i % 2)
			que.push_back(a[i]);
		else
			que.push_front(a[i]);

	if(n % 2)
		for(int i = 0; i < n; i++) cout << que[i] << " ";
	else
		for(int i = n - 1; i >= 0; i--) cout << que[i] << " ";
	return 0;
}
