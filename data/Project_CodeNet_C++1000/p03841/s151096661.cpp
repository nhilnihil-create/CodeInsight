#include<bits/stdc++.h>
using namespace std;
const int N=510*510;
pair<int,int> f[N];
int x[N];
int res[N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		f[i]=make_pair(x[i],i);
		res[x[i]]=i;
	}
	sort(f+1,f+n+1);
	int pos=1;
	for(int i=1;i<=n;i++){
		int id=f[i].second;
		for(int j=1;j<f[i].second;j++){
			while(pos<=n*n&&res[pos])pos++;
			res[pos]=id;
		}
		if(pos>f[i].first){puts("No");return 0;}
	}
	for(int i=1;i<=n;i++){
		int id=f[i].second;
		for(int j=n-id;j;j--){
			while(pos<=n*n&&res[pos])pos++;
			if(pos<x[id]){puts("No");return 0;}
			res[pos]=id;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++)printf("%d ",res[i]);
}