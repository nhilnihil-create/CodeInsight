#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int M=1e5+5;
struct each{
	int l,r;
}a[N];
vector<int>d[M];
int n,m,b[M],ans[M];
bool com(each x,each y){
	return x.l<y.l;
}
void add(int x,int y){
	while(x<=m){
		b[x]+=y;
		x+=x&-x;
	}
}
int query(int x){
	int ans=0;
	while(x){
		ans+=b[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	int top=1;
	sort(a+1,a+n+1,com);
	for(int i=1;i<=m;i++){
		while(top<=n&&a[top].l==i)
			add(i,1),add(a[top++].r+1,-1);
		for(int j=i;j<=m;j+=i)	d[j].push_back(i);

		int si=d[i].size();
		for(int j=0;j<si;j++){
			if(i+d[i][j]<=m)	ans[d[i][j]]+=query(i)-query(i+d[i][j]);
			ans[d[i][j]]+=query(i)-query(i-d[i][j]);
		}
	}
	for(int i=1;i<=m;i++)	printf("%d\n",ans[i]);
	return 0;
}
