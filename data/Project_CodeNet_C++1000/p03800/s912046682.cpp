#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#include <complex>
#include <numeric>
#include <climits>
#include <stack>
#include <clocale>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <deque>
#include <queue>
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define rept(i,n)for(int i=0;i<(int)(n);i++)
#define fi first
#define se second
using namespace std;
string p;
int s[100100],p1[100100],n;
int main(){
	cin>>n;
	cin>>p;
	int i,j;
	for(i=0;p[i];i++)
	{
		if(p[i]=='o')p1[i+1]=0;
		else p1[i+1]=1;
	}
	p1[n+1]=p1[1];
	for(i=0;i<8;i++)
	{
		s[0]=i&1;
		s[1]=(i>>1)&1;
		s[2]=(i>>2)&1;
		for(j=2;j<=n+1;j++)
		{
			s[j+1]=s[j-2]^p1[j];
		}
		if(s[0]^s[n]^s[1]^s[n+1] || s[1]^s[n+1]^s[2]^s[n+2])continue;
		for(j=1;j<=n;j++){
			printf("%c",(s[j]^s[j-1])?'W':'S');
		}
		return 0;
	}
	printf("-1\n");
	return 0;
}
