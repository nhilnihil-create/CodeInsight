#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define MN 100005
int n;
int a[MN];
int d[MN];
int s[MN];
vector<int> h[MN];
queue<int> q;
bool cmp(int x,int y){
	return s[x]<s[y];
}
int main(){
	read(n);
	for(int i=2;i<=n;++i)read(a[i]),h[a[i]].pb(i),++d[a[i]];
	for(int i=1;i<=n;++i)if(!d[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(!--d[a[x]])q.push(a[x]);
		sort(h[x].begin(),h[x].end(),cmp);
		reverse(h[x].begin(),h[x].end());
		for(int i=0;i<(int)h[x].size();++i){
			s[x]=max(s[h[x][i]]+1+i,s[x]);
		}
	}
	cout<<s[1];
	return 0;
}
