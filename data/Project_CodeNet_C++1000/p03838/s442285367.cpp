#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int lli;
const long long int MaxN=500005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli arr[MaxN];
	void solve(){
		lli N,obj,i,j,p,q,res=0;
		cin>>N>>obj;
		if(N>=0&&obj>0)p=1;
		if(N>=0&&obj<=0)p=2;
		if(N<0&&obj>=0)p=3;
		if(N<0&&obj<=0)p=4;
		//cout<<p<<"\n";
		if(p==1){
			if(N<=obj)res=obj-N;
			else res=abs(obj-N)+2;
		}
		if(p==2){
			if(N<=abs(obj))res=abs(obj)-N+1;
			else res=abs(abs(obj)-N)+1;
		}
		if(p==3){
			if(abs(N)<=obj)res=obj-abs(N)+1;
			else res=abs(obj-abs(N))+1;
		}	
		if(p==4){
			if(abs(N)<abs(obj))res=abs(abs(N)-abs(obj))+2;
			else 	res=abs(abs(N)-abs(obj));
		}
		cout<<res;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
