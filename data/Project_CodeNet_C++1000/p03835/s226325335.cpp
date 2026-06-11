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

int main(){ _

	int K,S;
	cin >> K >> S;

	ll ans = 0;

	for(int i = 0; i <= K; i++){
		for(int j = 0; j <= K; j++){
			int k = S - i - j;
			if(k >= 0 && k <= K) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
