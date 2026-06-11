#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a,b,x;
	cin >> a >> b >> x;

	ll ans = b/x - (a-1)/x;
	if(!a && x != 1) ans++;

	cout << ans << endl;

	return 0;
}
