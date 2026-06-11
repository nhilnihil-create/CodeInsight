#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int a[N];
bool q[N];

int main() {
	int n, m; cin >> n >> m;
	q[1] = 1;
	for(int i = 1; i <= n; i++) a[i] = 1;

	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if(a[x]==0) continue;
		else {
			if(a[x] == 1) {
				if(q[x]) q[y] = 1;
				q[x] = 0;		
			} else {
				if(q[x]) q[y] = 1;
			}
			a[x]--, a[y]++;
		}
	}

	/*for(int i = 1; i <= n; i++) {
		cout << a[i] << " " << q[i] << endl;
	}
	*/
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(a[i] && q[i]) cnt++;
	cout << cnt;
}