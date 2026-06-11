#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int d, c;
	ll ans = 1, m = pow(10, 9) + 7;
	
	cin >> d >> c;
	if(abs(d-c) > 1) cout << 0;
	else{
		int m1 = max(d, c);
		int m2 = min(d, c);
		REP(i, 0, m2){
			ans *=  (m1-i);
			ans %= m;
			ans *=  (m2-i);
			ans %= m;
		}
		if(d == c) ans*=2;
		cout << ans%m;
	}
	
}
