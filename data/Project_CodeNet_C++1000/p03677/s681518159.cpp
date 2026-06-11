/*
Problem: guruguru (AtCoder 2650)
Algorithm: Math/Difference
Status:
*/

/*
f(s,e,x)=
	s=e:{
		0
	}
	
	s<e:{
		e-s     x<=s
		e-x+1   s<x<=e
		e-s     e<x
	}
	
	s>e:{
		e-x+1   x<=e
		m-s+e   e<x<=s
		m-x+e+1 s<x
	}
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <utility>
#include <list>
#include <ctime>
#include <memory.h>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

#define INF 1000000000000000000
typedef long long ll;

int n,m;
int a[100005];
ll b[100005];
ll k[100005];

void addb(int x,int y,ll z){
	if(x>y)return;
	b[x]+=z;
	b[y+1]-=z;
}

void addk(int x,int y,ll z){
	if(x>y)return;
	k[x]+=z;
	k[y+1]-=z;
}

int main()
{
	#ifndef ZZZYT
		//freopen(".in","r",stdin);
		//freopen(".out","w",stdout);
	#endif
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<n;i++){
		int s=a[i];
		int e=a[i+1];
		if(s==e){
			
		}
		else if(s<e){
			addb(1,s,e-s);
			addb(s+1,e,e+1);
			addb(e+1,m,e-s);
			
			addk(s+1,e,-1);
		}
		else{
			addb(1,e,e+1);
			addb(e+1,s,m-s+e);
			addb(s+1,m,m+e+1);
			
			addk(1,e,-1);
			addk(s+1,m,-1);
		}
	}
	for(int i=1;i<=m;i++){
		b[i]+=b[i-1];
		k[i]+=k[i-1];
	}
	
	ll ans=INF;
	for(ll x=1;x<=m;x++){
		ans=min(ans,b[x]+k[x]*x);
	}
	cout<<ans<<endl;
	
	return 0;
}
