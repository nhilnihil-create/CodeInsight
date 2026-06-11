#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
const int N=100005;
int n,m,Q,x[N],y[N];
map<pair<int,int> ,int> a;
ll ans[10];
void solve(int l,int r){
	if (l<1||r<1||l+2>n||r+2>m)return;
	int v=0;
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			v+=a.count(mp(l+i,r+j));
	ans[v]++;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&x[i],&y[i]);
		a[mp(x[i],y[i])]=1;
	}
	for (int i=1;i<=Q;i++)
		for (int j=0;j<=2;j++)
			for (int k=0;k<=2;k++)
				solve(x[i]-j,y[i]-k);
	for (int i=1;i<=9;i++)ans[i]/=i;
	for (int i=1;i<=9;i++)ans[0]-=ans[i];
	ans[0]+=(ll)(n-2)*(m-2);
	for (int i=0;i<=9;i++)printf("%lld\n",ans[i]);
}
