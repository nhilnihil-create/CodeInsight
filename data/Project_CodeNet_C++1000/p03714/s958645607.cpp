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
int main(){
	int N;
	ll a[300001];
	ll score=0;
	ll scoremax=-INFl;
	ll scorek[100001][2]={0};
	priority_queue<ll,vector<ll>,greater<ll> > left;
	priority_queue<ll,vector<ll>,less<ll> > right;
	scan(N);
	rep(i,3*N){
		scan(a[i]);
	}
	rep(i,N){
		left.push(a[i]);
		scorek[0][0]+=a[i];
	}
	for(int i=2*N;i<3*N;i++){
		right.push(a[i]);
		scorek[N][1]-=a[i];
	}
	for(int k=N+1;k<=2*N;k++){
		scorek[k-N][0]=scorek[k-N-1][0];
		if(a[k-1]>left.top()){
			scorek[k-N][0]-=left.top();
			scorek[k-N][0]+=a[k-1];
			left.pop();
			left.push(a[k-1]);
		}
	}
	for(int k=2*N-1;k>=N;k--){
		scorek[k-N][1]=scorek[k-N+1][1];
		if(a[k]<right.top()){
			scorek[k-N][1]+=right.top();
			scorek[k-N][1]-=a[k];
			right.pop();
			right.push(a[k]);
		}
	}
	for(int k=N;k<=2*N;k++){
		//printf("k:%d score0:%lld score1:%lld\n",k,scorek[k-N][0],scorek[k-N][1]);
		scoremax=max(scoremax,scorek[k-N][0]+scorek[k-N][1]);
	}
	prin(scoremax);
	return 0;
}
