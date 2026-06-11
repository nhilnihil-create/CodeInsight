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
	int N,M;cin>>N>>M;
	map<int,int> X[M];
	int sum[M] = {};int eve[M] = {};
	rep(i,0,N){
		int x; cin>>x;
		X[x % M][x / M] ++ ;
		sum[x % M] ++ ;
	}
	rep(i,0,M){
		for(pair<int,int> p:X[i]) eve[i] += p.second / 2;
	}
	int ans = sum[0] / 2;
	if(M % 2 == 0) ans += sum[M/2] / 2;
    //print(sum,,M);print(eve,,M);
	rep(i,1,(M+1)/2){
        int a = i, b = M - i;
		if(sum[a]-2*eve[a] > sum[b]-2*eve[b]) swap(a, b);
		if(sum[a] >= sum[b] - 2 * eve[b]) ans += sum[b] - eve[b] + (sum[a] + 2 * eve[b] - sum[b]) / 2;
		else ans += sum[a] + eve[b];
	}cout<<ans<<endl;
}