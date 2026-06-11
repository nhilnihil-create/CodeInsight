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
	int a, b, c,ans=0,ans2=0,an,bn,cn;
	cin >> a >> b >> c;
	while (1) {
		ans2++;
		if (ans2 > 10000000) {
			cout << -1 << endl;
			return 0;
		}

		if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
			an = b / 2 + c / 2;
			//cout << a << endl;
			bn = a / 2 + c / 2;
			//cout << b<< endl;
			cn = a / 2 + b / 2;
			//cout << c<< endl;
			ans++;
			a = an;
			b = bn;
			c = bn;
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}
