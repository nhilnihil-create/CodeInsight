#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
int ans[11], cur, pos;
char ch[2];

int query(long long x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",ch);
	if(ch[0]=='Y') return 1;
	return 0;
}

int main()
{
	int len = 1;
	long long now = 1, res;
	for(;len<=11;len++,now*=10) if(!query(now)) break;
	if(len==12)
	{
		now = 9; res = 1;
		for(;;now=now*10+9, res*=10)
			if(query(now))
			{
				printf("! %lld\n",res); fflush(stdout);
				return 0;
			}
	}
	else -- len;
	long long l = 1, r = 1, mid, ans;
	fo(i,2,len) l *= 10; r = l*10-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(query(mid*10ll)) {ans = mid; r = mid - 1;}
		else l = mid + 1;
	}
	printf("! %lld\n",ans);
	fflush(stdout);
	return 0;
}