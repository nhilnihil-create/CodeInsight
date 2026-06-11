#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = n; i >= 0; --i)
#define P pair<int, int>
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;
using namespace std;

ull lcm(ull a,  ull b) {
	return a/__gcd(a,b)*b;
}

int main() 
{
	int n;
	cin >> n;
	ull LCM = 1LL;
	rep(i,n) {
		ull period;
		cin >> period;
		LCM=lcm(LCM, period);
	}
	cout << LCM << endl;
}