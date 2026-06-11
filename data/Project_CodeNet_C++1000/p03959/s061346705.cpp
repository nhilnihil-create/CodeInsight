#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	long T[N+1],A[N+1]; T[0] = 0; A[N] = 0;
	rep(i,1,N+1) cin>>T[i];
	rep(i,0,N) cin>>A[i];
	long H[N] = {};
	rep(i,0,N){
		if(T[i] < T[i+1]) H[i] = T[i+1];
		if(A[i] > A[i+1]) H[i] = A[i];
		if(T[i] < T[i+1] && A[i] > A[i+1])if(T[i+1] != A[i]){
			cout<<0<<endl;
			return 0;
		}
	}
	long ans = 1;
	rep(i,0,N){
        if(H[i] == 0) (ans *= min(T[i], A[i])) %= mod;
        else if(H[i] > min(T[i+1], A[i])) ans = 0;
    }
	cout<<ans<<endl;
}