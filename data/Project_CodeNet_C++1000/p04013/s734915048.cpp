#include<bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <limits>
#include <iostream>
#include <assert.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	int x,y,cost;
};
int x[51];
ll dp[2501][51][51]={};
int main(){

	int n,a;
	cin>>n>>a;

	rep(i,n){
		cin>>x[i+1];
		dp[0][0][i]=1;
	}
	for(int i=1; i<n+1; i++){
		for(int j=1; j<=i; j++){
			for(int k=1; k<2501; k++){
				if(x[i]<=k)dp[k][j][i]+=dp[k-x[i]][j-1][i-1];
				dp[k][j][i]+=dp[k][j][i-1];
			}
		}
	}
	ll total=0;
	for(int j=1; j<n+1; j++){
		for(int k=1; k<2501; k++){
			if(k%j==0&&k/j==a)total+=dp[k][j][n];
		}
	}
	cout<<total<<endl;
	return 0;

}

