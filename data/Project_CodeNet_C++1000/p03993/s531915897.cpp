#include<bits/stdc++.h>
using namespace std;

bool visited[100005];

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		if (a[a[i]] == i) {
			cnt++;
			visited[a[i]] = true;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
