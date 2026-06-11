#pragma GCC optimize(2) 
#include<bits/stdc++.h>
#define rg register
#define il inline
using namespace std;
typedef long long ll;
const int mod=1e9+7;
il int gi(){
	rg int o=0,fl=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')fl=-1,ch=getchar();
	while(isdigit(ch))o=o*10+ch-'0',ch=getchar();
	return fl*o;
}
int n,m,k,cnt[10];
map<pair<int,int>,int>book;
int main(){
	n=gi(),m=gi(),k=gi();
	while(k--){
		int x=gi(),y=gi();
		for(int i=max(1,x-2);i<=min(n-2,x);++i)
			for(int j=max(1,y-2);j<=min(m-2,y);++j)
				book[make_pair(i,j)]++; 
	}
	for(map<pair<int,int>,int>::iterator It=book.begin();It!=book.end();++It)
		++cnt[It->second],++k;
	printf("%lld",1ll*(n-2)*(m-2)-k-1);
	for(int i=1;i<=9;++i)printf("\n%d",cnt[i]);
	return 0;
}
