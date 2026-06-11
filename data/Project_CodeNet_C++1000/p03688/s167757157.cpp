#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100100
#define No printf("No\n");return 0;
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
int T,n,a[N],vis[N],p[N],tot; 
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	bool ok=true;
	tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=n||a[i]<1){
			ok=false;
			break;
		}
		++vis[a[i]];
		if(vis[a[i]]==1){
			p[++tot]=a[i];
			if(tot>2){
				ok=false;break;
			} 
		}
	}
	if(!ok){
		No;
	}
	bool tmp=false;
	if(tot==1){
		if(p[1]==n-1||p[1]<=n/2){
			tmp=true;
		}
	}
	else{
		if(p[1]>p[2])swap(p[1],p[2]);
		if(p[1]+1==p[2]){
			int res=p[2]-vis[p[1]];
			if(res>=1&&res<=vis[p[2]]/2){
				tmp=true;
			}
		}
	}
	if(tmp){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
