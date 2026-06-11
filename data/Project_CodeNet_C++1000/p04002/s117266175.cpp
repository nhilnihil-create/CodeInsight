#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=101010;
int H, W, n;
map<pii, int> F;
vector<pii> v;
bool vis[N][9];
ll cnt[10];
const int dx[9]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[9]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
const int sx[9]={1, 1, 1, 0, 0, 0, -1, -1, -1};
const int sy[9]={1, 0, -1, 1, 0, -1, 1, 0, -1};
int main(){
	scanf("%d%d%d", &H, &W, &n);
	rep(i, 0, n){
		int x, y;
		scanf("%d%d", &x, &y);
		F[mp(x, y)]=i;
		v.pb(mp(x, y));
	}
	rep(i, 0, n){
		rep(j, 0, 9){
			if(vis[i][j])continue;
			vis[i][j]=1;
			int x, y;
			x=v[i].fi+sx[j];
			y=v[i].se+sy[j];
			int c=0;
			bool ok=1;
			rep(k, 0, 9){
				int nx=x+dx[k], ny=y+dy[k];
				if(nx<=0||nx>H||ny<=0||ny>W){
					ok=0;
					continue;
				}
				if(F.count(mp(nx, ny))){
					c++;
					vis[F[mp(nx, ny)]][k]=1;
				}
			}
			if(ok)cnt[c]++;
		}
	}
	cnt[0]=1ll*(W-2)*(H-2);
	rep(i, 1, 10)cnt[0]-=cnt[i];
	rep(i, 0, 10)printf("%lld\n", cnt[i]);
	return 0;
}
