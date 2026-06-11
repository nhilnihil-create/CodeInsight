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
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
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



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;
	int sum1[100010] = { 0 };
	int sum2[100010] = { 0 };

	eFOR(i, 1, S.size()) {
		if (S[i-1] == 'A')sum1[i] = sum1[i - 1] + 1;
		else sum1[i] = sum1[i - 1] + 2;
		//cout << sum1[i] << " ";
	}
	//cout << endl;
	eFOR(i, 1, T.size()) {
		if (T[i-1] == 'A')sum2[i] = sum2[i - 1] + 1;
		else sum2[i] = sum2[i - 1] + 2;
		//cout << sum2[i] << " ";
	}
	//cout << endl;

	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; c--;
		//cout << sum1[b] <<" "<< sum1[a] << " " << sum2[d] <<" "<< sum2[c] << endl;
		if ((sum1[b] - sum1[a]) % 3 == (sum2[d] - sum2[c]) % 3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

