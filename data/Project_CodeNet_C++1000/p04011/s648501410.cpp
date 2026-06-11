#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

const int INF = 1000000000;

int main() {FIN
    
    int n, k, x, y, t = 0;
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> y;
    
    t += min(n, k) * x;
    if (n > k)
		t += (n - k) * y;
	cout << t << "\n";
    
    return 0;
}
