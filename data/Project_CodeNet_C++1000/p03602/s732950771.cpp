#include <bits/stdc++.h>


#define debug(x) cerr<< #x << ": "<< x << endl;
#define print(x) cerr<< x << endl;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define REP(i,x,y) for(int i=x;i<y;i++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define sqr(x) ((x)*(x))

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ones(x) __builtin_popcountll(x)
using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 330;
ll a[MAXN][MAXN], d[MAXN][MAXN];
int n;
const ll INF = 1e16;
int main(){
   fastio;
   cin >> n;

	REP(i,0,n) REP(j,0,n) {cin >> a[i][j]; d[i][j] = a[i][j];}
	
	REP(k,0,n){
		REP(i,0,n){
			REP(j,0,n){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	REP(i,0,n) REP(j,0,n) if(d[i][j] != a[i][j]) {cout<<-1<<endl; return 0;}
	
	REP(k,0,n){
		REP(i,0,n){
			REP(j,i + 1,n){
				if(k == i || k == j) continue;
				if(d[i][j] == d[i][k] + d[k][j]){
					d[i][j] = INF;
				}
			}
		}
	}

	ll ans = 0;
	REP(i,0,n) REP(j,i+1,n) if(d[i][j] != INF) ans += d[i][j];
	cout<<ans<<endl;

   return 0;
}

