#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	long long int a[100000], d[100000];
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
		a[i]--;
	}
	for(int i=0; i<n-1; i++){
		d[i]=a[i+1]-a[i];
		if(d[i]<0) d[i]+=m;
	}
	long long int s0[100000]={};
	for(int i=0; i<n-1; i++){
		if(a[i+1]-d[i]+1>=0){
			if(a[i+1]-d[i]+2<m) s0[a[i+1]-d[i]+2]--;
			if(a[i+1]+1<m) s0[a[i+1]+1]++;
		}else{
			s0[1]--;
			s0[a[i+1]+1]++;
			if(a[i+1]-d[i]+2+m<m) s0[a[i+1]-d[i]+2+m]--;
		}
	}
	long long int s1[100000]={};
	for(int i=1; i<m; i++){
		s1[i]=s1[i-1]+s0[i];
	}
	for(int i=0; i<n-1; i++){
		if(a[i+1]+1<m) s1[a[i+1]+1]+=(d[i]-1);
	}
	long long int s2[100000];
	s2[0]=0;
	for(int i=0; i<n-1; i++){
		if(a[i+1]-d[i]+1>=0){
			s2[0]+=d[i];
		}else{
			s2[0]+=(a[i+1]+1);
		}
	}
	long long int ans=s2[0];
	for(int i=1; i<m; i++){
		s2[i]=s2[i-1]+s1[i];
		if(ans>s2[i]) ans=s2[i];
	}
	printf("%lld\n", ans);
	return 0;
}