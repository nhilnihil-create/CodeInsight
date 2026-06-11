#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>
#include <string>
#define FI first
#define SE second
#define PF push_front
#define PB push_back
#define PPF pop_front
#define PPB pop_back
#define MA make_pair
#define ll long long
#define PA pair<int,int>
#define VE vector<int>
#define VP vector<PA>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POSSIBLE(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Possible(i) cout<<(i?"Possible":"Impossible")<<endl
using namespace std;
//
const int INF=1e9+7;
const int mod=998244353;
//
struct poi{
	int X;int Y;int Z;
	bool operator<(const poi&R)const{
		return X==R.X ? Y==R.Y ? Z<R.Z : Y<R.Y : X<R.X;
	}
};
//
ll GCD(ll A,ll B){
  return (B==0)?(A):(GCD(B,A%B));
}
ll LCM(ll A,ll B){
  return A/GCD(A,B)*B;
}
//
int main(){
	int N;
	ll A[300][300];
	vector<pair<ll,pair<int,int> > > V;
	cin>>N;
	FOR(i,0,N){
		FOR(j,0,N){
			cin>>A[i][j];
			if(i<j){
				V.PB(MA(A[i][j],MA(i,j)));
			}
			if(i!=j){
				A[i][j]=1e15;
			}
		}
	}
	sort(V.begin(),V.end());
	ll ans=0;
	FOR(k,0,V.size()){
		ll v=V[k].FI;
		int x=V[k].SE.FI;
		int y=V[k].SE.SE;
		if(A[x][y]>v){
			ans+=v;
			FOR(i,0,N){
				FOR(j,0,N){
					A[i][j]=min(A[i][j],A[i][x]+v+A[y][j]);
					A[i][j]=min(A[i][j],A[i][y]+v+A[x][j]);
				}
			}
		}
	}
	FOR(i,0,V.size()){
		ll v=V[i].FI;
		int x=V[i].SE.FI;
		int y=V[i].SE.SE;
		if(A[x][y]!=v){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}