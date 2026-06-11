#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

ll a[100010];


map<ll,int> num,ord;

ll ans[100010];

int main(int argc, char const *argv[])
{
	int n;cin>>n;

	priority_queue<ll> pq;

	rep(i,n) {
		cin>>a[i];
		if (!num.count(a[i])) {
			ord[a[i]]=i;
			num[a[i]]++;
			pq.push(a[i]);
		} else {
			num[a[i]]++;
		}
	}

	ll cur = pq.top();pq.pop();
	int cnt = num[cur];
	ll nxt;
	int left = ord[cur];
	bool end = false;

	while (1) {
		// cout<<cur<<endl;
		if (pq.empty()) {
			nxt = 0;
			end = true;
		} else {
			nxt = pq.top();pq.pop();
		}
		ans[left]+=(ll)cnt*(cur-nxt);
		cnt+=num[nxt];
		cur=nxt;
		left = min(left,ord[cur]);
		if (end) break;
	}

	rep(i,n) {
		cout<<ans[i]<<endl;
	}

	return 0;
}