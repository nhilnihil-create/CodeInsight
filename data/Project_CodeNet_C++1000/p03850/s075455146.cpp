#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <stack>
#include <cmath>
#include <string>
#define SIZE 100005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

int A[SIZE];
int tp[SIZE];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	ll ret=0;
	scanf("%lld",&ret);
	n--;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		int a;
		scanf("%d",&a);
		if(str[0]=='-') tp[i]=0;
		else tp[i]=1;
		A[i]=a;
	}
	bool up=true;
	vector <P> vx;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		if(up&&tp[i]==1)
		{
			ret+=A[i];
		}
		else
		{
			if(up)
			{
				up=false;
				vx.push_back(P(A[i],0));
				sum=0;
			}
			else if(tp[i]==0)
			{
				vx[vx.size()-1].second=sum;
				vx.push_back(P(A[i],0));
				sum=0;
			}
			else
			{
				sum+=A[i];
			}
		}
	}
	if(up)
	{
		printf("%lld\n",ret);
		return 0;
	}
	vx[vx.size()-1].second=sum;
	ll all=0;
	for(int i=0;i<vx.size();i++) all+=vx[i].first+vx[i].second;
	ll now=-INF;
	for(int i=0;i<vx.size();i++)
	{
		all-=vx[i].first+vx[i].second;
		now=max(now,all-(vx[i].first+vx[i].second));
		all-=vx[i].first;
		all+=vx[i].second;
	}
	now=max(now,all);
	printf("%lld\n",ret+now);
	return 0;
}
