#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N;cin>>N;
	int A[N]; int x = inf,y = 0;
	rep(i,0,N){
		cin>>A[i];
		x = min(x, A[i]);
		y = max(y, A[i]);
	}
	if(x == y){
		if(x == N - 1 || 2 * x <= N) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}else if(x + 1 == y){
		int a = 0,b = 0;
		rep(i,0,N){
			if(A[i] == x) a++;
			else b++;
		}
		if(a < y && y <= a + b / 2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}else cout<<"No"<<endl;
}