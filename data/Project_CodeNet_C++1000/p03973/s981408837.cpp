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
	long a; long res = 0;
	long ans = 0;
	rep(i,0,N){
		cin>>a;
		if(res + 1 < a){ ans += (a - 1) / (res + 1); res = max(res, (long)1); }
		else res = max(res, a);
	}cout<<ans<<endl;
}