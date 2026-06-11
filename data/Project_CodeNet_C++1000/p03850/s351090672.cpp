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
#include <assert.h>
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
int n;
ll a[100005];
vector <ll> vec;
vector <int> pos;
vector <bool> b;
ll sumabs[100005];

int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("input.txt","r",stdin);
	cin>>n;
	char x;
	cin>>a[0];
	for(int i=1;i<n;i++)
	{
		cin>>x;
//		while(x!='+' && x!='-') x=getchar();
		cin>>a[i];
//		scanf("%d",a+i);
		if(x=='-') a[i]=-a[i];
//		x=getchar();
	}
	ll res=0;
	for(int i=0;i<n;)
	{
		ll sum=0;
		while(a[i]>0 && i<n)
		{
			sum+=a[i];
			i++;
		}
		vec.push_back(sum);
		while(a[i]<0 && i<n)
		{
			vec.push_back(a[i]);
			i++;
		}
	}
//	for(int i=0;i<10;i++)
//	{
//		cout<<vec[i]<<' ';
//	}
//	cout<<endl;
	while(vec.back()==0) vec.pop_back();
	n=vec.size();
	memset(a,0,sizeof(a));
	memset(sumabs,0,sizeof(sumabs));
	for(int i=0;i<n;i++)
	{
		a[i]=vec[i];
		res+=a[i];
	}
	sumabs[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		sumabs[i]=sumabs[i+1]+abs(a[i]);
	}
	ll now=0;
	for(int i=0;i<n;i++)
	{
		now+=a[i];
		if(a[i]<0)
		{
			res=max(res,now-a[i+1]+sumabs[i+2]);
//			cout<<now-a[i+1]+sumabs[i+2]<<endl;
		}
//		cout<<now<<' '<<a[i+1]<<' '<<sumabs[i+2]<<endl;
	}
	cout<<res<<endl;
//	ll res=0;
//	for(int i=0;i<n;i++)
//	{
//		if(vec[i]>0) pos.push_back(i);
//	}
//	int nn;
//	for(int i=0;i<n-1;i++)
//	{
//		if(vec[i]<0 && vec[i+1]<0)
//		{
//			nn=i;
//			break;
//		}
//	}
//	
//	ll res=0;
//	for(int i=0;i<pos.size();i++)
//	{
//		int p=pos[i];
//		bool tb=false;
//		if(p!=0 && p!=n-1)
//		{
//			if(-vec[p+1]>vec[p])
//			{
//				tb=true;
//			}
//		}
//		b.push_back(tb);
//	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<vec[i]<<' ';
//	}
//	cout<<endl;
//	int l=0;
//	for(int i=0;i<pos.size();i++)
//	{
//		ll block=0;
//		for(int j=pos[i]+2;j<(i==(int)pos.size()-1?n:pos[i+1]);j++)
//		{
//			block+=abs(a[j]);
//		}
//		if(i==(int)pos.size()-1 && pos[i]==n-1)
//		{
//			block+=abs(a[pos[i]]);
//		}
//		else
//		{
//			if(!b[i]) block+=a[pos[i]]+a[pos[i]+1];
//			else block+=-a[pos[i]]-a[pos[i]+1];
//		}
//		res+=block;
//		cout<<i<<' '<<block<<endl;
//	}
//	cout<<res<<endl;
	return 0;
}