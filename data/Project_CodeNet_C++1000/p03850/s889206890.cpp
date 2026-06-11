#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll inf=1e16;
const int MN=100000;
int N;
ll a[MN];
char o[MN];
ll dp[MN][3];
int main(){
	cin>>N;
	rep(i,N){
		cin>>a[i];
		if(i==N-1) break;
		cin>>o[i];
	}
	rep(i,N) rep(j,3) dp[i][j]=-inf;
	dp[0][0]=a[0];
	rep(i,N-1){
		rep(j,3) if(dp[i][j]!=-inf){
			if(o[i]=='-' && j!=2) chmax(dp[i+1][j+1],dp[i][j]+(j%2==0?-a[i+1]:a[i+1]));
			chmax(dp[i+1][j],dp[i][j]+ (((j%2==0) ^ (o[i]=='+'))?-a[i+1]:a[i+1]) );
		}
		chmax(dp[i+1][1],dp[i+1][2]);
		chmax(dp[i+1][0],dp[i+1][1]);
	}
	cout<<dp[N-1][0]<<endl;
}
