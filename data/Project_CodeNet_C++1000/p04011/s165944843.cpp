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

	int N,K,X,Y;
	cin >> N >> K >> X >> Y;

	ll ans = 0;
	ans += X*min(K,N);
	ans += max(0,(N - K))*Y;

	cout << ans << endl;

	return 0;
}
