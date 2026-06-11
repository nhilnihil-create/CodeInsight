#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<uint32_t> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
const int N = 100*1000+7;



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	LL x,y;
	cin >> x >> y;
	if(x > y)
		swap(x,y);

	if(x+1 >= y)
		cout << "Brown";
	else
		cout << "Alice";

	return 0;
}
