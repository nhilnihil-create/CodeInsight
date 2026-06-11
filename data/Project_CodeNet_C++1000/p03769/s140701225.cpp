#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int cnt;
vector<int>q1,q2;
int main()
{
	//freopen("tt.in","r",stdin);
	scanf("%lld",&n);n++;
	int now=100;
	while(n!=1)
	{
		if(n&1)n--,q1.push_back(now--);
		else n>>=1,q2.push_back(now--);
		cnt++;
	}
	printf("%d\n",cnt*2);
	for(int i=0;i<q1.size();i++)printf("%d ",q1[i]);
	for(int i=q2.size()-1;i>=0;i--)printf("%d ",q2[i]);
	for(int i=now+1;i<=100;i++)printf("%d ",i);
	return 0;
}
