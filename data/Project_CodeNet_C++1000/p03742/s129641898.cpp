#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	ll X, Y;
	cin >> X >> Y;
	cout << (abs(X-Y)>=2 ? "Alice" : "Brown") << endl;
    return 0;
}