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
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
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
	ll L,T,X[100001];
	int W[100001];
	vll ans;
	ll collisionnumall=0;
	ll X0zahyo;
	scan(N);scan(L);scan(T);
	rep(i,N){
		scan(X[i]);scan(W[i]);
		if(W[i]==1){
			ans.push_back((X[i]+T)%L);
			if(i==0) X0zahyo=(X[i]+T)%L;
		}
		else{
			ll tmp=(X[i]-T)%L;
			if(tmp<0) tmp+=L;
			ans.push_back(tmp);
			if(i==0) X0zahyo=tmp;
		}
		if(i!=0&&W[i]!=W[0]){
			double initialcoltime;
			if(W[0]==1){
				initialcoltime=(double)(X[i]-X[0])/2+eps;
			}
			else{
				initialcoltime=(double)(X[0]+L-X[i])/2+eps;
			}
			double colcadance=(double)L/2+eps;
			ll colnum;
			if(initialcoltime>=T) colnum=0;
			else colnum=(ll)((T-initialcoltime)/colcadance)+1;
			collisionnumall+=colnum;
		}
	}
	sort(ans.begin(),ans.end());
	ll X0indexbase;
	if(W[0]==1){
		X0indexbase=lower_bound(ans.begin(),ans.end(),X0zahyo)-ans.begin();
	}
	else{
		X0indexbase=upper_bound(ans.begin(),ans.end(),X0zahyo)-ans.begin()-1;
	}
	ll X0index;
	if(W[0]==1){
		X0index=X0indexbase-collisionnumall;
		X0index%=N;
		if(X0index<0) X0index+=N;
	}
	else{
		X0index=X0indexbase+collisionnumall;
		X0index%=N;
		if(X0index<0) X0index+=N;
	}
	rep(i,N){
		prin(ans[(X0index+i)%N]);
	}
	return 0;
}
