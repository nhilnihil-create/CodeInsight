#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[200100],t[200100],res;
vector<int>v;
void ADD(int x){while(x<=m)t[x]++,x+=x&-x;}
int ASK(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
signed main(){
	scanf("%lld%lld",&n,&m),v.push_back(0);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]),s[i]-=m,s[i]+=s[i-1],v.push_back(s[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),m=v.size();
	for(int i=0;i<=n;i++)s[i]=lower_bound(v.begin(),v.end(),s[i])-v.begin()+1,res+=ASK(s[i]),ADD(s[i]);
	printf("%lld\n",res);
	return 0;
}