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

	int N, M;
	cin >> N >> M;
	VI X(N);
	vector<VI> modX(M);
	REP(i, N) cin >> X[i];
	SORT(X);
	REP(i, N) modX[X[i] % M].push_back(X[i]);

	int ans = 0;
	eREP(i, M/2) {
		if ((i + i) % M == 0) {
			ans += modX[i].size() / 2;
			continue;
		}
		int s = modX[i].size(), t = modX[M - i].size();
		ans += min(s, t);

		if (s < t) {
			int a = 0;
			while (t - 2 >= s&& a < modX[M - i].size() - 1) {
				if (modX[M - i][a] == modX[M - i][a + 1]) {
					ans++;
					t -= 2;
					a++;
				}
				a++;
				if (t - 2 < s || a >= modX[M - i].size() - 1) break;
			}		
		}
		else{
			int a = 0;
			while (s - 2 >= t && a < modX[i].size() - 1) {
				if (modX[i][a] == modX[i][a + 1]) {
					ans++;
					s -= 2;
					a++;
				}
				a++;
				if (s - 2 < t || a >= modX[i].size() - 1) break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

