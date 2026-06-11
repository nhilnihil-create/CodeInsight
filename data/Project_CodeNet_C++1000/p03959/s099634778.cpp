#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX=1e5+5;
const lli MOD=1e9+7;

lli t[MAX],a[MAX];
bool tmx[MAX],amx[MAX];

int main(){
	int N;
	cin>>N;
	rep1(i,N){
		cin>>t[i];
		if(t[i-1]<t[i])tmx[i]=true;
	}
	rep1(i,N)cin>>a[i];
	for(int i=N;i>=1;i--){
		if(a[i]>a[i+1])amx[i]=true;
	}
	int ht[MAX];
	rep1(i,N){
		int h;
		if( tmx[i]&& amx[i]){
			if(t[i]!=a[i])h=0;
			else h=1;
		}
		if( tmx[i]&&!amx[i]){
			if(t[i]>a[i])h=0;
			else h=1;
		}
		if(!tmx[i]&& amx[i]){
			if(t[i]<a[i])h=0;
			else h=1;
		}
		if(!tmx[i]&&!amx[i]){
			h=min(t[i],a[i]);
		}
		ht[i]=h;
	}
	lli ans=1;
	rep1(i,N){
		ans=(ans*(lli)ht[i])%MOD;
	}
	cout<<ans;
}