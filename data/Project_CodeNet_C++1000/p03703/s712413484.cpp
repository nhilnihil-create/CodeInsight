#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=5e5+5;
int n,k;
ll a[mxn],s[mxn],ans;
vector<ll>v;map<ll,int>m;
struct fenwick{
	int t[mxn],sz;
	inline void init(int siz){memset(t,0,sizeof(t));sz=siz;}
	inline void add(int x,int val){for(int i=x;i<=sz;i+=(i&-i))t[i]+=val;}
	inline int ask(int x){int rt=0;for(;x;x-=(x&-x))rt+=t[x];return rt;}
}fen;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i],a[i]-=k;
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i],v.push_back(s[i]),ans+=(s[i]>=0);
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();++i)m[v[i]]=i+1;
	for(int i=1;i<=n;++i)s[i]=m[s[i]];
	fen.init(n*2);
	for(int i=1;i<=n;++i){
		ans+=fen.ask(s[i]);
		fen.add(s[i],1);
	}
	cout<<ans<<'\n';
}