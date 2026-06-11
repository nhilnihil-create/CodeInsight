#include <bits/stdc++.h>
                            
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define f first
#define s second
 
#define inf (int)1e9 + 7
 
#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
#define mp(x,y) make_pair(x,y)
 
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
 
#define pb push_back
#define ppb pop_back
 
#define bitcoin __builtin_popcount
 
#define endl "\n"
 
#define in(x) insert(x)
 
#define sz(x) (int)x.size()
 
#define all(x) x.begin(),x.end()
 
#define pw2(x) (1ll<<x) //2^x
 
#define forit(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
 
#define sqr(x) ((x) * 1ll * (x))
 
#define UpdateRandom srand (time(NULL));
 
using namespace std;
 
const int N = (int)5e5 + 7, MOD = (int)1e9 + 7;

int n,m,cl;
int a[N];

int X;
int b[N];

int res[200][200];

int main(){
		
	NFS
	
	cin >> n >> m;	
	
	cin >> cl;
	
	for(int i=1;i<=cl;i++)cin >> a[i];
	
	for(int i=1;i<=cl;i++){
		for(int j=1;j<=a[i];j++){
			X++;
			b[X]=i;
		}
	}
	
	int cur=0;
	
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				cur++;
				res[i][j]=b[cur];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				cur++;
				res[i][j]=b[cur];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout << res[i][j] << ' ';
		cout << endl;
	}

	ioi
}