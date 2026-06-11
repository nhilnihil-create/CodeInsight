#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
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
    long res = 1;
	rep(i,0,N/2) (res*=2)%=mod;
    cout<<res<<endl;
}