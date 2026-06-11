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

	int a,b,c,d;
	cin >> a >> b >> c >> d;

	cout << max(a*b,c*d) << endl;

	return 0;
}
