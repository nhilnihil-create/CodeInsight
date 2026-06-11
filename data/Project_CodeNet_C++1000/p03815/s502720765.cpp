#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll X;

int main(){ _

	cin >> X;

	ll l = 0, r = (1e16 + 10);
	while(l < r){
		ll m = l + (r - l)/2;

		ll at = (m/2)*(11) + 6*(m & 1);

		if(at >= X)
			r = m;
		else l = m + 1;
	}

	cout << l << endl;


	return 0;
}
