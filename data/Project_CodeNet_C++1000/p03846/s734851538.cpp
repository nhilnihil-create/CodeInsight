#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
long modpow(long x,int n,long p){
	int i=0;long res=1;
	while(n>=(1<<i)){
		if(n&(1<<i)) (res*=x)%=p;
		i++;
		x=(x*x)%p;
	}return res;
}
int main(){
	int N;cin>>N;
	int cnt[N] = {}; int a;
	rep(i,0,N){
		cin>>a; cnt[a]++;
		cnt[abs(N - 2*i - 1)]--;
	}
	rep(i,0,N)if(cnt[i]){
		cout<<0<<endl;
		return 0;
	}
	cout<<modpow(2,N/2,mod)<<endl;
}