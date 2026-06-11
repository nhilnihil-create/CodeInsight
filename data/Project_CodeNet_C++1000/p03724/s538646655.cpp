#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int N, M;
	cin >> N >> M;
	vector <int> d(N, 0);
	int a, b;
	while(cin >> a >> b) {
		d[a - 1] ^= 1;
		d[b - 1] ^= 1;
	}
	cout << (count(all(d), 1) ? "NO" : "YES");
    return 0;
}