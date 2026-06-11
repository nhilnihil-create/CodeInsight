#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> mp; 
long long ans[10];

int up[]={-1,0,1,-1,0,1,-1,0,1},le[]={-1,-1,-1,0,0,0,1,1,1};

main()
{
	long long h,w;
	int n;
	scanf("%lld %lld %d",&h,&w,&n);
	ans[0]=(h-2)*(w-2);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		for(int j=0;j<9;j++)
		{
			int na=a+up[j],nb=b+le[j];
			if(na<=1||nb<=1||na>=h||nb>=w)continue;
			ans[mp[make_pair(na,nb)]]--;
			mp[make_pair(na,nb)]++;
			ans[mp[make_pair(na,nb)]]++;
		}
	}
	for(int i=0;i<=9;i++)printf("%lld\n",ans[i]);
}