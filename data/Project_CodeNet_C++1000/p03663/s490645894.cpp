#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

int query(LL x){
	cout << "? " << x << endl;
	cout.flush();
	string s; cin >> s;
	return s == "Y" ? 1 : 0;
}

int ans[10][2];
LL pwr[10];

int main(){
	if (query(1000000000)){
		for (LL i = 1; ; i *= 10)
			if (query(i << 1)){
				cout << "! " << i << endl;
				return 0;
			}
	}
	for (LL i = 1000000000; i >= 1; i /= 10) if (query(i)){
		LL l = i + 1, r = i * 10 - 1, res = -1;
		while (l <= r){
			LL mid = l + r >> 1;
			if (query(mid * 1000))
				res = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << "! " << res << endl;
		return 0;
	}
	return 0;
}