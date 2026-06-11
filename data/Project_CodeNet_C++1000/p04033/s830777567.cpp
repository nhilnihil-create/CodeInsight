#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<20, mod = 924844033;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b;
	if(a <= 0 && b >= 0) cout << "Zero";
	else if(a > 0 || abs(a-min(b, -1)+1)%2 == 0) cout << "Positive";
	else cout << "Negative";
}
