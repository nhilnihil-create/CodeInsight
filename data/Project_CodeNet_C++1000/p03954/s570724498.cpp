/*************************************************************************
	> File Name: pyramid.cpp
	> Author: codecode
	> Created Time: 2019年11月07日 星期四 08时31分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+5;
int n,a[maxn];
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
inline bool jujuakioi(const int &k){
	 if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))return 1;
	 if((a[n-1]>k&&a[n]>k)||(a[n]>k&&a[n+1]>k))return 0;
	 for(int i=1;i<n-1;i++){
		 if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))return 1;
		 if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))return 0;
	 }
	 return a[1]<=k;
}
int main(){
	cin>>n;
	for(int i=1;i<n*2;i++)a[i]=read();
	int l=1,r=n*2-1;
	while(l<r){
		int mid=(l+r)/2;
		if(jujuakioi(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
