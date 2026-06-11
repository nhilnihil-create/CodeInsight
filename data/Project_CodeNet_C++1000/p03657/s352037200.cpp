#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int a, b; cin >> a >> b;
	if(a%3==0||b%3==0||(a+b)%3==0)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}