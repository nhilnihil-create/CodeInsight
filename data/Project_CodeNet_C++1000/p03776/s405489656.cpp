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

const int MAX_C = 51;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}

ll v[60];

int main(int argc, char const *argv[])
{
	int n,a,b;cin>>n>>a>>b;

	rep(i,n) cin>>v[i];

	sort(v,v+n);reverse(v,v+n);

	map<ll,int> ma;

	rep(i,n) {
		if (!ma.count(v[i])) {
			ma[v[i]]=1;
		} else {
			ma[v[i]]++;
		}
	}

	calc_com();

	ma[0]=0;

	ll ans=0;

	if (ma[v[0]]>=a) {
		for (int i=a;i<=min(b,ma[v[0]]);i++) {
			ans+=Com[ma[v[0]]][i];
		}
		cout << fixed << setprecision(10) << (double)v[0] << endl;
		cout<<ans<<endl;
	} else {
		int cnt = 0;
		ll sum=0;
		for (auto it = ma.end();it!=ma.begin();it--) {
			if (it==ma.end()) continue;
			// cout<<it->first<<endl;
			if (cnt+(it->second)<=a) {
				sum+=(it->first)*(it->second);
				cnt+=it->second;
			} else {
				sum+=(it->first)*(a-cnt);
				ans+=Com[it->second][a-cnt];
				break;
			}
		}
		double ave = sum/(double)a;
		cout << fixed << setprecision(10) << ave << endl;
		cout<<ans<<endl;
	}

	return 0;
}