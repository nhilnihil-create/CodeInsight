#include<bits/stdc++.h>
#define hh puts("")
#define int long long
using namespace std;
int n,s,a[100005],cha[100005],m,k,t[100005];
inline int read(){
	int ret=0,ff=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*ff;
}
inline void ksm(int p){
	while(p){
		if(p&1){
			for(int i=1;i<=n;i++) t[i]=cha[a[i]];
			for(int i=1;i<=n;i++) cha[i]=t[i];
		}
		p>>=1;
		for(int i=1;i<=n;i++) t[i]=a[a[i]];
		for(int i=1;i<=n;i++) a[i]=t[i];
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cha[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++) a[i]=i;//改存位置 
	m=read(),k=read();
	for(int i=1;i<=m;i++){
		int t=read();
		swap(a[t],a[t+1]);
	}
	//当前存的是一套体操后对应位置
	//b[i]表示原来在i位置,一套体操后的位置 
	ksm(k);
	for(int i=1;i<=n;i++){
		s+=cha[i];//把差分数组加上去
		printf("%lld.0\n",s);
	}
	return 0;
}