#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 2510
int OFF;

int ans[MAXN][MAXN];
int N,M,D,p;
queue<pair<pi, int>> Q;
vector<pair<pi,int>> V;
char mk[5] = {'A', 'R','Y','G','B'};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>D;

	if (D%2 == 1){
		p = (D+1)/2;
		Q.push(mp(mp(p+D,1+D), 1));
		Q.push(mp(mp(1+D,p+1+D), 2));
		Q.push(mp(mp(p+1+D,D+1+D), 3));
		Q.push(mp(mp(D+1+D,p+D), 4));
		int dx[] = {D+1,-D+1,-(D+1),-(-D+1)};
		int dy[] = {D-1,D+1,-(D-1), -(D+1)};
		while (SZ(Q)){
			pi cur = Q.front().f;
			int in = Q.front().s;
			ans[cur.f][cur.s] = in;
			V.pb(Q.front());
			Q.pop();
			// cout<<cur.f<<' '<<cur.s<<' '<<in<<'\n';
			for (int i=0;i<4;++i){
				int cx = cur.f + dx[i];
				int cy = cur.s + dy[i];
				if (cx <= 0 || cy <= 0 || cx > N+2*D || cy > M+2*D)continue;
				if (ans[cx][cy])continue;
				ans[cx][cy] = in;
				Q.push(mp(mp(cx,cy), in));
			}
		}

		for (auto i : V){
			pi t = i.f;
			int in = i.s;
			for (int j=1-p;j<=p-1;++j){
				for (int k=1-p+abs(j); k<= p-1-abs(j);++k){
					int cx = t.f + j;
					int cy = t.s + k;
					if (cx <= D || cy <= D || cx > N+D || cy > M+D)continue;
					ans[cx][cy] = in;
				}
			}
		}
		for (int i=1;i<=N;++i){
			for (int j=1;j<=M;++j)cout<<mk[ans[i+D][j+D]];
			cout<<'\n';
		}
		
	}else {

		p = D/2;
		Q.push(mp(mp(D,D), 1));
		Q.push(mp(mp(D+p,D-p), 2));
		Q.push(mp(mp(D+p,D+p), 3));
		Q.push(mp(mp(D,2*D), 4));
		int dx[] = {0,0,D, -D};
		int dy[] = {2*D,-2*D,-D, D};

		while (SZ(Q)){
			pi cur = Q.front().f;
			int in = Q.front().s;
			ans[cur.f][cur.s] = in;
			V.pb(Q.front());
			Q.pop();
			// cout<<cur.f<<' '<<cur.s<<' '<<in<<'\n';
			for (int i=0;i<4;++i){
				int cx = cur.f + dx[i];
				int cy = cur.s + dy[i];
				if (cx < 0 || cy < 0 || cx >= N+2*D || cy >= M+2*D)continue;
				if (ans[cx][cy])continue;
				ans[cx][cy] = in;
				Q.push(mp(mp(cx,cy), in));
			}
		}
		for (auto i : V){
			pi t = i.f;
			int in = i.s;
			for (int j=1-p;j<=p-1;++j){
				for (int k=1-p+abs(j); k<= p-abs(j);++k){
					// cout<<j<<' '<<k<<'\n';
					int cx = t.f + j;
					int cy = t.s + k;
					if (cx < D || cy < D || cx >= N+D || cy >= M+D)continue;
					ans[cx][cy] = in;
				}
			}
			// break;
		}
		for (int i=0;i<N;++i){
			for (int j=0;j<M;++j)cout<<mk[ans[i+D][j+D]];
			cout<<'\n';
		}
	}
}
