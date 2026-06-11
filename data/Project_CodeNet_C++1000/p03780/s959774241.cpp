#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int N,K;
vint ac;
int dp[5000][5001];
int huyosu(int MIN,int MAX){
	if(MIN+1==MAX) return MIN;
	int MID=(MIN+MAX)/2;
	vint a;
	int noted;
	rep(i,N){
		if(i!=MID) a.push_back(ac[i]);
		else noted=ac[i];
	}
	rep(i,N){
		rep(k,K+1){
			dp[i][k]=INF;
		}
	}
	dp[0][0]=0;
	rep(i,N-1){
		rep(j,K+1){
			dp[i+1][j] = dp[i][j];
			if(j>=a[i]){
				dp[i+1][j] = min(dp[i][j-a[i]]+1,dp[i+1][j]);
			}
		}
	}
	int flag=0;
	for(int k=K-noted;k<K;k++) if(dp[N-1][k]<INF) flag=1;
	//printf("MIN:%d MAX:%d MID:%d flag:%d\n",MIN,MAX,MID,flag);
	if(flag) return huyosu(MIN,MID);
	else return huyosu(MID,MAX);
}
int main(){
	int a[5001];
	scan(N);scan(K);
	rep(i,N){
		scan(a[i]);
		ac.push_back(a[i]);
	}
	sort(ac.begin(),ac.end());
	if(ac[0]>=K){
		prin(0);
	}
	else{
		prin(huyosu(-1,N)+1);
	}
	return 0;
}
