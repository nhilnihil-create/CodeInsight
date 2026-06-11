// :)
// "Khodaya, be man "Tagwaye setiz" biamooz ta
//  dar anbuh masuliat nalaghzam ..." -Shariati
#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int> pii32;
typedef pair<int64,int64> pii64;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5+10;
const int64 MO = 1e9+7;
const int64 IN = 1e9;

char f;

bool check (int64 x) {
	cout << "? " << x << "\n";
	cout.flush();
	cin >> f;
	return (f == 'Y');
}

void getAns (int l) {
	int64 cur = 0;
	for (int i = 0; i < l - 1; i++) {
		int l, r, mid;
		l = 0;
		r = 10;
		while (r - l > 1) {
			mid = (l + r) >> 1;
			if (check(cur * 10 + mid))
				l = mid;
			else
				r = mid;
		}
		cur = cur * 10 + l;
	}
	for (int i = 0; i < 10; i++)
		if (cur * 100 + i * 11 > 0 && check(cur * 100 + i * 11)) {
			cur = cur * 10 + i;
			break;
		}
	cout << "! " << max(1LL, cur) << "\n";
	cout.flush();
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int64 X = 1;
	int len = 13;
	for (int i = 0; i < 12; i++)
		X *= 10;
	for (int i = 0; i < 13; i++) {
		if (!check(X)) {
			X /= 10;
			len--;
			continue;		
		}
		if (i == 0) {
			X = 9;
			len = 1;
			while (1) {
				if (!check(X)) {
					X *= 10;
					len++;
					continue;
				}
				getAns(len);
				break;
			}
			break;
		}
		getAns(len);
		break;
	}
}
