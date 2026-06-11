#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll I=1000000000000000001;
const int INF=1000000;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int dp[41][401][401];
int a[41],b[41],c[41];
int main(void) {

	int n,ma,mb;
	cin>>n>>ma>>mb;
	rep(i,n)cin>>a[i]>>b[i]>>c[i];
	rep(k,n+1){
		for(int i=0; i<=400; i++){
			for(int j=0; j<=400; j++){
				dp[k][i][j]=INF;
			}
		}
	}
	dp[0][0][0]=0;
	rep(i,n){
		for(int j=0; j<=400; j++){
			for(int k=0; k<=400; k++){
				if(dp[i][j][k]==INF)continue;
				dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+a[i]][k+b[i]]=min(dp[i][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
			}
		}
	}
	int total=INF;
	for(int j=1; j<=400; j++){
		for(int k=1; k<=400; k++){
			if(j*mb==k*ma){
				total=min(total,dp[n][j][k]);
			}
		}
	}
	if(total==INF)total=-1;
	cout<<total<<endl;
	return 0;

}
