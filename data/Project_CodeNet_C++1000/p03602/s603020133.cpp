#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int need[301][301];
int fl[301][301];
int n;

int main()
{
	read(n);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) read(fl[i][j]);
	for(int s=1; s<=n; ++s){
		vector<pp> d;
		for(int i=1; i<=n; ++i) d.eb(fl[s][i], i);
		sort(all(d));
		for(int j=1; j<n; ++j){
			int p=d[j].y;
			int mp=s, md=fl[s][p];
			for(int k=0; k<j; ++k){
				int b=d[k].y;
				if(fl[s][p] > fl[s][b] + fl[b][p]){
					puts("-1");
					return 0;
				}
				if(fl[s][p] == fl[s][b] + fl[b][p]){
					if(md > fl[b][p]){
						md = fl[b][p];
						mp = b;
					}
				}
			}
			need[p][mp] = need[mp][p] = 1;
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(need[i][j]) ans += fl[i][j];
	printf("%lld\n", ans);
	return 0;
}
