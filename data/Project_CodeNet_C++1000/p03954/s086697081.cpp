#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (!isdigit(ch)) f=(ch=='-')?-f:f,ch=getchar();
	while (isdigit(ch)) ret=(ret<<1)+(ret<<3)+ch-48,ch=getchar();
	return ret*f;
}

inline bool check(const int &k){
	if (a[n]<=k&&(a[n-1]<=k||a[n+1]<=k)) return 1;
	if (a[n]>k&&(a[n-1]>k||a[n+1]>k)) return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k)) return 1;
        if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k)) return 0;
    }
    return a[1]<=k;
}
int main(){
	n=read();
	for (int i=1;i<=2*n-1;i++) a[i]=read();
	int L=0,R=(n<<1)-1;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid)) R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",L);
	return 0;
}