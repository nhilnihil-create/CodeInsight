#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ans,cnt[200010];
char s[200010];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		cnt[s[i]-'a']++;
	}
	for(i=0;i<26;i++)ans+=cnt[i]*(cnt[i]-1)/2;
	ans=n*(n-1)/2+1-ans;
	printf("%lld",ans);
}