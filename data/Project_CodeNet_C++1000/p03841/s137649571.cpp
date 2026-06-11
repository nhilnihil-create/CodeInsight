#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,x[N],a[N];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > Q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		a[x[i]]=i;
		for (int j=1;j<i;j++) Q.push(pii(x[i],i));
	}
	for (int i=1;i<=n*n;i++)
	if (a[i]){
		int id=a[i];
		for (int j=0;j<n-id;j++) Q.push(pii(1e9,id));
	}
	else{
		if (Q.empty()) return puts("No"),0;
		if (i>Q.top().first) return puts("No"),0;
		a[i]=Q.top().second;
		Q.pop();
	}
	puts("Yes");
	for (int i=1;i<=n*n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}