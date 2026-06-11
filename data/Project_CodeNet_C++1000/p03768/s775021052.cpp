#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN

/*
操作を逆からみる．一度塗られた場所はもう塗られない
操作の方法は(v,d)のペアの数だけある（visitedで管理）
f(v,d,c)：vからd以内の点をcで塗る
はf(v,d-1,c)とf(u,d-1,c)に分解できる．
*/

ll n,m,visited[100010][11],color[100010]={},q,vq[100010],dq[100010],cq[100010];
vector<ll> v[100010];

void f(ll p,ll d,ll c){
	if(visited[p][d]==1)return;
	if(d==0){
		color[p]=c;
	}else{
		f(p,d-1,c);
		rep(i,v[p].size()){
			f(v[p][i],d-1,c);
		}
	}
	visited[p][d]=1;
}

int main(void){
	cin>>n>>m;
	rep(i,100010)rep(j,11)visited[i][j]=0;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin>>q;
	rep(i,q)cin>>vq[i]>>dq[i]>>cq[i];
	irep(i,q){
		f(vq[i],dq[i],cq[i]);
		// reg(i,1,n)printf("%lld ",color[i]);
		// printf("\n");
	}
	reg(i,1,n)cout<<color[i]<<endl;
	return 0;
}