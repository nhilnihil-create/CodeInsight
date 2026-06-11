#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector<int>vec[100010];
int a[100010];
int n;
int len;
int x,y;
int size[100010];
int siz[100010];
int xx[100010];
bool flag=1;
void output(bool b){
	if(b)cout<<"Fennec";
	else cout<<"Snuke";
	exit(0);
}
void work(){
//	cout<<"hello\n";
	int pos=len-1;
	int lps=0;
	while(pos>=0){
		siz[xx[pos]]=size[xx[pos]]-lps;
		lps=size[xx[pos]];
		pos--;
	}
	ll sum1=siz[1],sum2=siz[n];
	if(len==2){
		output(sum1>sum2);
	}
	int pos1=0,pos2=len-1;
	int cnt=0;
	while(pos1+1<pos2){
//		cout<<sum1<<' '<<sum2<<' '<<cnt<<'\n';
		cnt++;
		if(cnt&1){
			pos1++;
			sum1+=siz[xx[pos1]];
		}
		else {
			pos2--;
			sum2+=siz[xx[pos2]];
		}
	}
//	cout<<sum1<<' '<<sum2<<' '<<cnt<<'\n';
	if(sum1==sum2){
		if(cnt&1)cout<<"Fennec";
		else cout<<"Snuke";
		exit(0);
	}
	output(sum1>sum2);
}
void dfs(int idx,int par,int step){
//	cout<<idx<<'\n';
	size[idx]=1;
	a[step]=idx;
	if(idx==n&&flag){
		for(int i=0;i<step+1;i++){
			xx[i]=a[i];
		}
		flag=0;
		len=step+1;
	}
	for(int i=0;i<vec[idx].size();i++){
		if(vec[idx][i]!=par)dfs(vec[idx][i],idx,step+1),size[idx]+=size[vec[idx][i]];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		vec[x].pb(y);
		vec[y].pb(x);
	}
//	for(int i=1;i<=n;i++)cout<<i<<':'<<vec[i].size()<<'\n';
	dfs(1,-1,0);
	work();
	return 0;
}