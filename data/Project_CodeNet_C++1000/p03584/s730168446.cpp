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
#include<iomanip>
#include<set>
#include "bits/stdc++.h"
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N;
	ll K,A[100001],B[100001];
	scan(N>>K);
	rep(i,N){
		scan(A[i]>>B[i]);
	}
	ll ans=0;
	ll Know=K;
	vint onenum;
	for(int i=0;Know;i++){
		if(Know&1) onenum.push_back(i);
		Know>>=1;
	}
	vll Klist;
	Klist.push_back(K);
	rep(i,onenum.size()){
		Klist.push_back(((K>>onenum[i])<<onenum[i])-1);
		//printf("onenum:%d shift:%lld k:%lld\n",onenum[i],K>>onenum[i],((K>>onenum[i])<<onenum[i])-1);
	}
	rep(i,Klist.size()){
		ll k=Klist[i];
		ll sum=0;
		rep(j,N){
			if((k|A[j])==k) sum+=B[j];
		}
		ans=max(ans,sum);
		//printf("i:%d k:%lld sum:%lld\n",i,k,sum);
	}
	prin(ans);
	return 0;
}
