#include <bits/stdc++.h>
using namespace std;
int ant,lt,t,ops[100009],asp[100009],fin[100009];//fin[]存储最终结果 
long long ranking;
int main(){
	scanf("%d%d%d",&ant,&lt,&t);
	for(int i=1;i<=ant;i++)	scanf("%d%d",&ops[i],&asp[i]);
	for(int i=1;i<=ant;i++)
		if(asp[i]==1)	ranking=(long long)(ranking+((ops[i]+t)/lt))%ant;
		else{
			int add=ops[i]-t;
			add=(add-lt+1)/(-1*lt);
			ranking=(long long)ranking-add;
			if(ranking<0)	ranking=(long long)((-1*ranking+ant-1)/ant)*ant+ranking;
		}
	for(int i=1;i<=ant;i++)
		if(asp[i]==1)	fin[i]=(ops[i]+t)%lt;
		else{
			fin[i]=ops[i]-t;
			if(fin[i]<0)	fin[i]=((-1*fin[i]+lt-1)/lt)*lt+fin[i];
		}
	sort(fin+1,fin+1+ant);
	for(int i=1;i<=ant;i++){
		int now=i+ranking;
		if(now>ant)	now%=ant;
		printf("%d\n",fin[now]);
	}
	return 0;
}