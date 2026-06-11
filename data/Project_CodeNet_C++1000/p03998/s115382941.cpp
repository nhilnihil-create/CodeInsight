#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int aindex=0, bindex=0, cindex=0;
	char index = a[0];
	while (1) {
		if (index == 'a') {
			index = a[aindex];
			aindex++;
			if (aindex == a.size()+1) {
				cout << "A" << endl;
				return 0;
			}
		}
		else if (index == 'b') {
			index = b[bindex];
			bindex++;
			if (bindex == b.size()+1) {
				cout << "B" << endl;
				return 0;
			}
		}
		else if (index == 'c') {
			index = c[cindex];
			cindex++;
			if (cindex == c.size()+1) {
				cout << "C" << endl;
				return 0;
			}
		}
	}
	return 0;
}

