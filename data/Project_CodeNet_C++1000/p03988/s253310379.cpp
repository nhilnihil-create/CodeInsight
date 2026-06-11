#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nn 65536*4
#define lf double
int n;int leng[nn];
int maxi,mini=12432342;int cnt[nn];
#define err {puts("Impossible");exit(0);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&leng[i]);
		maxi=max(maxi,leng[i]);mini=min(mini,leng[i]);
		cnt[leng[i]]++;
	}
	if(n==2) 
	{
		puts("Possible");
		exit(0);	
	}
//	if(cnt[1]>=2) err;
	if(maxi%2==0)
	{
		if(mini!=maxi/2) err;
		for(int i=maxi;i>mini;i--) if(cnt[i]<2) err;
		if(cnt[mini]!=1) err;
	}
	else
	{
		if(mini!=maxi/2+1) err;
		for(int i=maxi;i>=mini;i--) if(cnt[i]<2) err;
		if(cnt[mini]!=2) err;
	}
	puts("Possible");
	return 0;
} 