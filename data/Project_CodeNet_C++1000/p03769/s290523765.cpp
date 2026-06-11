#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 100010
#define M 11

typedef long long ll;
const int INF=1<<30;

deque<int> Q;

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	ll n; int a[60]; int m=0;
	cin >> n ;n++;
	while (n)
	{
		a[m++]=n&1;
		n>>=1;
	}
	int k=0;
	for (int i=m-2;i>=0;i--)
	{
		Q.push_back(++k);
		if (a[i]) Q.push_front(++k);
	}
	for (int i=1;i<=k;i++) Q.push_back(i);
	printf("%d\n",(int)Q.size());
	for (int i=0;i<Q.size();i++) printf("%d%c",Q[i],i==Q.size()-1? '\n':' ');
	return 0;
}