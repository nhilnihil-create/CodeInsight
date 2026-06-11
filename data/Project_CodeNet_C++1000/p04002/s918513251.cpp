#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
#include<random>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define int long long
#define inf 1145141919
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
typedef pair<int, P> PP;
struct edge { int to, cost; };
const long long mod = 10000000;
int a[114514], b[114514];
int ans[15];
vector<P>V;
map<P, int>M;
signed main() {
	int h, w, n; cin >> h >> w >> n;
	rep(i, n) {
		cin >> a[i] >> b[i];
		M[P(a[i], b[i])] = 1;
		for (int j = -2; j <= 0; j++) {
			for (int k = -2; k <= 0; k++) {
				if(1<=a[i]+j&&a[i]+j<=h-2&&1<=b[i]+k&&b[i]+k<=w-2)V.push_back(P(a[i]+j, b[i]+k));
			}
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	rep(i, V.size()) {
		int cnt = 0;
		rep(j, 3) {
			rep(k, 3) {
				if (M[P(V[i].first + j, V[i].second + k)])cnt++;
			}
		}
		ans[cnt]++;
	}
	ans[0] += (h-2)*(w-2) - V.size();
	rep(i, 10)cout << ans[i] << endl;

}