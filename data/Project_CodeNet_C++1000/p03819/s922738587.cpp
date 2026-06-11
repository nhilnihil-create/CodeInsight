#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,m,f[N];
vector<int> q[N];

void modify(int x,int t){
	if (x>m) return;
	f[x]+=t;modify(x+(x&-x),t);
}

int query(int x){
	if (!x) return 0;
	return f[x]+query(x-(x&-x));
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
 
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		int l=read(),r=read();
		q[r-l+1].push_back(l);
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<(int)q[i].size();j++)
			modify(q[i][j],1),modify(q[i][j]+i,-1);
		n-=q[i].size();
		int ans=0;
		for (int j=i;j<=m;j+=i)
			ans+=query(j);
		printf("%d\n",n+ans);
	}
	return 0;
}