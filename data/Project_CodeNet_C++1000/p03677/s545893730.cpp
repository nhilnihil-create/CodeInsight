#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,k;
int a[100005];

struct status
{
	int start_now;
	int end_now;
	int len;
}t[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	ll now=0;
	ll addition=0;
	for(int i=0;i<n-1;i++)
	{
		bool debug=(i==0);
		int st=a[i];
		int ed=a[i+1];
		if(ed<st) ed+=k;
		now+=ed-st;
		if(ed-st<=1) continue;
		st+=2;
		if(st>=k && ed>=k)
		{
			st-=k;
			ed-=k;
		}
		else if(st<k && ed>=k)
		{
			t[0].start_now++;
			t[st].start_now++;
			t[ed-k].len+=ed-st+1;
			t[ed-k].end_now++;
			addition+=k-st;
			continue;
		}
		t[st].start_now++;
		t[ed].end_now++;
		t[ed].len+=ed-st+1;
	}
//	for(int i=0;i<2*k-1;i++)
//	{
//		cout<<t[i].start_now<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<2*k-1;i++)
//	{
//		cout<<t[i].end_now<<' ';
//	}
//	cout<<endl;
	ll res=now;
	int toadd=0;
	for(int i=0;i<k;i++)
	{
		if(i==0) now-=addition;
		int i1=i;
		int i2=i+k;
		toadd+=t[i1].start_now;
//		toadd+=t[i2].start_now;
		now-=toadd;
//		cout<<now<<' '<<toadd<<endl;
		res=min(res,now);
		toadd-=t[i1].end_now;
//		toadd-=t[i2].end_now;
		now+=t[i1].len;
//		now+=t[i2].len;
	}
	cout<<res<<endl;
	return 0;
}