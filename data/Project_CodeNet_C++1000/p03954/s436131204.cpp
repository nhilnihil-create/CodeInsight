#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int n,a[200005],l=1,r=(n*2-1),ans;
bool check(int x){
	for(int i=0;i<=n-2;i++){
		if((a[n+i]<=x&&a[n+i+1]<=x)||(a[n-i]<=x&&a[n-i-1]<=x))return 1;
		if((a[n+i]>x&&a[n+i+1]>x)||(a[n-i]>x&&a[n-i-1]>x))return 0;
	}
	if(a[1]>x)return 0;
	else return 1;
}
int main(){
	in(n);
	for(int i=1;i<=n*2-1;i++)in(a[i]);
	r=n*2-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}