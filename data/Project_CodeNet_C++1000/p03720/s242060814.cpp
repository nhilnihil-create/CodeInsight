#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>	
#include<limits>
#include<ctime>
#include<stack>	
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
	
typedef long long ll;
using namespace std;
const ll x=1000000007;
int mod(ll a){
	return a%x;
}

int main(){
	ll n,m;
	cin>>n>>m;
	ll a[m],b[m],c[n];
	for(int i=0;i<n;i++){
		c[i]=0;
	}
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		c[a[i]-1]++;
		c[b[i]-1]++;
	}
	for(int i=0;i<n;i++){
		cout<<c[i]<<endl;
	}
}
