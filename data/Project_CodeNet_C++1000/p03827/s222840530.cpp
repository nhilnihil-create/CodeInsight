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

	int N;
	cin >> N;
	N = 0;

	string S;
	cin >> S;

	int ans = N;
	for(auto x : S){
		if(x == 'I') N++;
		if(x == 'D') N--;
		ans = max(ans,N);
	}

	cout << ans << endl;

	return 0;
}
