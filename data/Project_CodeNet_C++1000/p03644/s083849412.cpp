#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n, ans = 0,i=0,j=0,k;
	cin >> n;
	if (n == 3) {
		cout << 2 << endl;
		return 0;
	}
	vector<int>a(n + 1),b(n+1);
	rep(i, n+1) {
		
		k = i;
		while (1) {
			k = k / 2;
			if (k % 2 == 0)ans++;
			if (k == 0)break;
		}
		a.at(i) = ans;
		b.at(i) = ans;
		ans = 0;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	
	rep(j, n + 1) {
		if (a.at(0) == b.at(j)) {
			if (j == 0) {
				cout << n << endl;
				return 0;
			}
			if (j == 3) {
				cout << 2 << endl;
				return 0;
			}
			cout << j << endl;
			return 0;
		}
	}
	
	return 0;
}