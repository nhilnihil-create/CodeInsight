#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define INF 1000000001
#define INFL 1000000000000000001
#define M 1000000007
string s;
ll n,ans=1,cnt[505];
int main(void){
	cin>>s;
	n=s.size();
	ans+=n*(n-1LL)/2LL;
	for(int i=0;i<n;i++)cnt[s[i]]++;
	for(int i='a';i<='z';i++)ans-=cnt[i]*(cnt[i]-1LL)/2LL;
	printf("%lld\n",ans);
}
