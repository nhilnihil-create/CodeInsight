#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

ll a,b,x;
ll f(ll n) {
	if (n == -1) return 0;
	else return n/x + 1;
} 
int main() {
	cin>>a>>b>>x;
	cout << f(b)-f(a-1) << endl;
	return 0;
}