#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,s[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int L=read()-1,R=read();
		int r=1;
		for(int l=1;l<=L;l=r+1){
			r=min(L/(L/l),R/(R/l));
			if(L/l<R/l){
				++s[l],--s[r+1];
			}
		}
		s[L+1]++,s[R+1]--;
	}
	for(int i=1;i<=m;++i){
		s[i]+=s[i-1];
		printf("%d\n",s[i]);
	}
	return 0;
}
