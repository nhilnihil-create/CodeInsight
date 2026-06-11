#include <algorithm>
#include <cstdio>
int x[505],id[505],ans[250005];
bool cmp(int a,int b){return x[a]<x[b];}
int main(){
	int n;bool flag=1;
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		if (!ans[x[i]]) ans[x[i]]=i;
			else flag=0;
		id[i]=i;
	}
	std::sort(id+1,id+n+1,cmp);
	for (int i=1,j=1;i<=n && flag;i++){
		for (int k=1;k<id[i];j++)
			if (!ans[j]) ans[j]=id[i],k++;
		if (j>x[id[i]]) flag=0;
	}
	for (int i=n,j=n*n;i>=1 && flag;i--){
		for (int k=id[i];k<n;j--)
			if (!ans[j]) ans[j]=id[i],k++;
		if (j<x[id[i]]) flag=0;
	}
	if (flag){
		printf("Yes\n");
		for (int i=1;i<=n*n;i++) printf("%d ",ans[i]);
	}
	else printf("No\n");
}