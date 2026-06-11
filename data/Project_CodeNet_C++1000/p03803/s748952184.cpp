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

	int a,b;

	cin >> a >> b;

	if(a == 1) a += 13;
	if(b == 1) b += 13;

	if(a < b) cout << "Bob" << endl;
	else if(a == b) cout << "Draw\n";
	else cout << "Alice" << endl;

	return 0;
}
