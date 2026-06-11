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
using namespace std;

const int maxn = 52;

ll K,k;
ll a[maxn];

int main()
{
	scanf("%lld",&K); k=K%50ll;
	for(int i=50;i>50-k;i--) a[i]=50;
	for(int i=50-k;i>=1;i--) a[i]=50-k-1;
	k=K/50ll;
	for(int i=1;i<=50;i++) a[i]+=k;
	printf("50\n");
	for(int i=1;i<=50;i++) printf("%lld ",a[i]);
	
	return 0;
}
