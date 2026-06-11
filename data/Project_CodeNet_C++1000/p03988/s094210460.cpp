#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int main(){
	int N;cin>>N;
	int cnt[N] = {};
	int a; int t = 0;
	rep(i,0,N){
		cin>>a;
		cnt[a]++; t = max(t, a);
	}rep(i,0,t+1){
		if(cnt[max(i, t-i)] >= 1) cnt[max(i, t-i)]--;
		else{ cout<<"Impossible"<<endl; return 0; }
	}rep(i,0,(t + 3) / 2){
		if(cnt[i]){ cout<<"Impossible"<<endl; return 0; }
	}cout<<"Possible"<<endl;
}