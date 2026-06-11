#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const int inf=1e9;
int main(){
	int N,K; cin>>N>>K;
	long a; long sum[2][N+1]; sum[0][0] = sum[1][0] = 0;
	rep(i,0,N){
		cin>>a;
		sum[0][i+1] = sum[0][i] + a;
		sum[1][i+1] = sum[1][i] + max(a, 0L);
	}
	long ans = 0;
	rep(i,0,N-K+1){
		int j = i + K;
		long res = 0;
		res += sum[1][i] - sum[1][0];
		res += max(sum[0][j] - sum[0][i], 0L);
		res += sum[1][N] - sum[1][j];
		ans = max(ans, res);
	}
	cout<<ans<<endl;
}