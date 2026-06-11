#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

const int INF = 1000000000;

int main() {FIN
    
    int n, i, j, mn = INF, mx = -INF, c, t;
    cin >> n;
    vi ns(n);
    for (i = 0; i < n; i++) {
		cin >> ns[i];
		mn = min(mn, ns[i]);
		mx = max(mx, ns[i]);
	}
	
	c = INF;
	for (i = mn; i <= mx; i++) {
		t = 0;
		for (j = 0; j < n; j++)
			t += (ns[j] - i) * (ns[j] - i);
		c = min(c, t);
	}
	
	cout << c << "\n";
    
    return 0;
}
