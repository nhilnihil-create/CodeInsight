#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int n, m;
	cin >> n >> m;
	vector <int> visited(n, 0), cnt(n, 1);
	visited[0] = 1;
	while(m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(visited[x]) {
			visited[y] = 1;
		}
		cnt[x]--;
		cnt[y]++;
		if(cnt[x] == 0) {
			visited[x] = 0;
		}
	}	
	cout << accumulate(all(visited), 0) << endl;
    return 0;
}