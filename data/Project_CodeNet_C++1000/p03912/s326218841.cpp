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
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
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
	int N,M;
	int X[100001];
	int xmodd[100001]={};
	int xmeven[100001]={};
	int num[100001]={};
	scan(N>>M);
	rep(i,N){
		scan(X[i]);
		num[X[i]]++;
	}
	int ans=0;
	rep1(i,100000){
		xmeven[i%M]+=num[i]/2;
		if(num[i]%2){
			xmodd[i%M]+=1;
		}
	}/*
	rep1(i,10){
		printf("num[%d]:%d\n",i,num[i]);
	}
	rep(i,M){
		printf("xmodd[%d]:%d xmeven[%d]:%d\n",i,xmodd[i],i,xmeven[i]);
	}*/
	ans+=xmeven[0]+xmodd[0]/2;
	rep1(i,M/2){
		int j=M-i;
		if(i==j) ans+=xmeven[i]+xmodd[i]/2;
		else{
			int oi=xmeven[i]*2+xmodd[i];
			int oj=xmeven[j]*2+xmodd[j];
			if(oi>oj){
				ans+=oj;
				if(xmodd[i]>oj) ans+=xmeven[i];
				else ans+=(oi-oj)/2;
			}
			else{
				ans+=oi;
				if(xmodd[j]>oi) ans+=xmeven[j];
				else ans+=(oj-oi)/2;
			}
		}
	}
	prin(ans);
	return 0;
}
