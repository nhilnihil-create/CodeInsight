#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N, k;
	cin >> N >> k;
	VI a(N), B(N);
	REP(i, N) {
		cin >> a[i] >> B[i];
	}
	int ma = 0, mask = 0;
	eREP(i, 30) {
		if (i == 0 || (k&(1 << i)) != 0) {
			int cmask = mask | ((k >> (i + 1)) << (i + 1));
			if (i == 0)cmask = k;
			int sum = 0;
			REP(i, N) {
				if ((cmask | a[i]) == cmask)sum += B[i];
			}
			ma = max(sum, ma);
		}
		mask |= (1 << i);
	}

	cout << ma << endl;

	return 0;
}

