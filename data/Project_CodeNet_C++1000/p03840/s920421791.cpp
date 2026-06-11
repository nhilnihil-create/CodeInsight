#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
#define INF 1e15
#define MOD 1000000007
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef long long ll;
#define END system("PAUSE");return 0
int a, b, c, d, e, f, g;
signed main() {
	cin >> a >> b >> c >> d >> e >> f >> g;
	//A:2個で+2
	//D:2個で+2
	//E:2個で+2
	//B:1個で+1
	//A1個+D1個+E1個で+3(高々1個まで)
	if (a&&d&&e)cout << max(b + ((a - 1) / 2 * 2) + ((d - 1) / 2 * 2) + ((e - 1) / 2 * 2) + 3, b + (a / 2 * 2) + (d / 2 * 2) + (e / 2 * 2)) << endl;
	else cout<< b + (a / 2 * 2) + (d / 2 * 2) + (e / 2 * 2) << endl;
	END;
}
