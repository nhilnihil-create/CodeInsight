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
	int W,H;cin>>W>>H;
	long P[W+1],Q[H+1]; P[W] = Q[H] = inf;
	long sum = 0;
	rep(i,0,W){ cin>>P[i]; sum += P[i]; }
	rep(i,0,H){ cin>>Q[i]; sum += Q[i]; }
	sort(P, P+W); sort(Q, Q+H);
	int j = 0;
	rep(i,0,W){
		while(P[i] > Q[j]) j++;
		sum += P[i] * (H - j);
	}
	j = 0;
	rep(i,0,H){
		while(Q[i] >= P[j]) j++;
		sum += Q[i] * (W - j);
	}cout<<sum<<endl;
}