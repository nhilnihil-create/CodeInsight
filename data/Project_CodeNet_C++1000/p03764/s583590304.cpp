#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define __ %=Mod
using namespace std;

const int maxn = 110000;
const ll Mod = 1e9+7;

int n,m;
int a[maxn],b[maxn];
ll ca,cb;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	for(int i=1;i<n;i++) (ca+=(ll)i*(n-i)%Mod*(a[i+1]-a[i])%Mod)__;
	for(int i=1;i<m;i++) (cb+=(ll)i*(m-i)%Mod*(b[i+1]-b[i])%Mod)__;
	printf("%lld\n",ca*cb%Mod);
	
	return 0;
}
