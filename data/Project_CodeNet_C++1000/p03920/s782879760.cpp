#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	int n;scanf("%d",&n);
	int k=1,s=1;
	while (s<n)
	{
		k++;s+=k;
	}
	for (int i=k;i;i--)
		if (n>=i) {printf("%d\n",i);n-=i;}
	return 0;
}

