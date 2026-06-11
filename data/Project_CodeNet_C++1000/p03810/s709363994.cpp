/* ***********************************************
Author        :axp
Created Time  :2017/2/4 22:24:36
TASK		  :D.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int md = 1e9+7;
const int N = 1e5+10;
int n,m;
int T;
map<int,int> mp;
int ar[N];
int l[N],r[N];

bool solve()
{
	if(n==1)return ar[1]!=1;
	ll sum=0;
	int now=0;
	int v;
	for(int i=1;i<=n;i++)
	{
		sum+=ar[i];
		if(ar[i]&1)
			now++,v=i;
	}
	if((sum-n)%2)return 1;
	if(now!=1 || ar[v]==1)return 0;
	ar[v]--;
	int t=ar[v];
	for(int i=1;i<=n;i++)t=__gcd(t,ar[i]);
	for(int i=1;i<=n;i++)ar[i]/=t;
	return 1-solve();
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
	bool ans=solve();
	puts(ans?"First":"Second");
    return 0;
}
