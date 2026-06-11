#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int main(){
	int N,x; cin>>N>>x;
	if(x == 1 || x == 2 * N - 1) cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		rep(i,0,2*N-1){
			cout<<(i + x + N - 1) % (2 * N - 1) + 1<<endl;
		}
	}
}