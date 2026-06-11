#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	long N;cin>>N;
	long A[N+1]; long sum = 0;
	rep(i,0,N){ cin>>A[i]; sum += A[i]; }
	if((2 * sum) % (N * (N + 1)) == 0){
		A[N] = A[0];
		long m = 2 * sum / N / (N + 1);
		long t;
		rep(i,0,N){
			t = m - (A[i+1] - A[i]);
            if(0 <= t && t <= N * m && t % N == 0) continue;
			else{ cout<<"NO"<<endl; return 0; }
		}cout<<"YES"<<endl;
	}else cout<<"NO"<<endl;
}