#include<bits/stdc++.h>
#define P push_back
#define L(x) ((x)&-(x))
using namespace std;
const int N=100005;
vector<int>e[N];
int n,m,s[N],a;
void U(int x,int u){while(x<=n)s[x]+=u,x+=L(x);}
int Q(int x){int r=0;while(x)r+=s[x],x-=L(x);return r;}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1,l,r;i<=m;i++)scanf("%d%d",&l,&r),e[r-l+1].P(l);
	for(int d=1;d<=n;d++){a=m;for(int i=d;i<=n;i+=d)a+=Q(i);for(int u:e[d])U(u,1),U(u+d,-1),m--;printf("%d\n",a);}
	return 0;
}