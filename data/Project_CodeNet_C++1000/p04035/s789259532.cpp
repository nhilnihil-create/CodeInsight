#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int main(){
	int N; long L; cin>>N>>L;
	long A[N];
	rep(i,0,N) cin>>A[i];
	rep(i,0,N-1){
		if(A[i] + A[i+1] >= L){
			cout<<"Possible"<<endl;
			for(int j = N-2; j > i; j--) cout<<j+1<<endl;
            rep(j,0,i+1) cout<<j+1<<endl;
			return 0;
		}
	}cout<<"Impossible"<<endl;
}