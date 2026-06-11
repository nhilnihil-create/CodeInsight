#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e3;
const int INF=1e9;
long area(long x,long y){
	if(x%2==0) return x/2;
	long res=INF;long a,b;
	rep(i,0,y+1){
		if((y-i)%2==0) res=min(res,abs((y-i)/2-i)*x);
		else{
			if(y-i>=x){ a=(y-i+1)/2*x; b=(y-i-1)/2*x; }
			else{ a=(x+1)/2*(y-i); b=(x-1)/2*(y-i); }
			res=min(res,max(a,x*i)-min(b,x*i));
		}//cout<<res<<" ";
	}return res;
}
int main(){
	long H,W;cin>>H>>W;
	if(H%3==0||W%3==0){ cout<<0<<endl;return 0; }
	cout<<min(area(H,W),area(W,H))<<endl;
}