#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 5;

int n, a[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k = 0;
	while(true) {
		int z = 0, f = 0, g = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] & 1)
				f++;
			else
				z++;
		}
		if(f == n) {
			cout << (k? "First" : "Second") << "\n";
			return 0;
		}
		if(z & 1) {
			cout << (!k? "First" : "Second") << "\n";		
    		return 0;
		}
		if((z % 2) == 0 && f > 1) {
			cout << (k? "First" : "Second") << "\n";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			if(a[i] & 1) {
				if(a[i] == 1) {
					cout << (k? "First" : "Second") << "\n";		
    				return 0;
				}
				else {
					a[i]--;
				}
				break;
			}
		}
		for (int i = 0; i < n; i++)
			g = __gcd(a[i], g);
		for (int i = 0; i < n; i++)
			a[i] /= g;
		k ^= 1;
	}
}