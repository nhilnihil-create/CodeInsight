#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define ll long long

#define debug_message 0
#define debug if (debug_message)

#define sz(x) (int)x.size()

ll i,t,j;
ll k,s,a,b,c,cnt;

int main(){
	scanf("%lld%lld",&k,&s);
	
	for (i=0; i<=k; ++i){
		for (t=0; t<=min(k,s-i); ++t){
			if (s-i-t<=k) ++cnt;
		}
	}
	
	printf("%lld\n",cnt);
	
	return 0;
}
/*

*/