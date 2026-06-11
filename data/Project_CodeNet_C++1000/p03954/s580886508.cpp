#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MAX=1e9+7;
int a[400020],b[400020],l,r,mid,ans,n;
bool cmp(int x,int y){
	return x<y;
} 
int check(int x){
	int p=0;
	int m=n;
	int last;
	int len=0;
	int now;
	if(a[m]>=x) last=1;
	else last=0;
	int w1=MAX,w0=MAX;
	for(int i=m+1;i<=2*n-1;i++){
		if(a[i]>=x) now=1;
		else now=0;
		if(now==last){
			if(now==1){
				w1=i-m;
			}
			else{
				w0=i-m;
			}
			break;
		}
		if(i==2*n-1) p++;
		last=now;
	}
	if(a[m]>=x) last=1;
	else last=0;
	for(int i=m-1;i>=1;i--){
		if(a[i]>=x) now=1;
		else now=0;
		if(now==last){
			if(now==1){
				w1=m-i;
			}
			else{
				w0=m-i;
			}
			break;
		}
		if(i==1) p++;
		last=now;
	}
	if(p==2){
		if(a[1]>=x) return 1;
		else return -1;
	}
	if(w1<=w0) return 1;
	else return -1;
}
int main(){
    //freopen("find.in","r",stdin);
    //freopen("find.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
    	scanf("%d",&a[i]);
    	b[i]=a[i];
    }
    sort(b+1,b+2*n,cmp);
    l=1;
    r=2*n-1;
    //
    //printf("%d %d\n",l,r);
    //
    while(l<=r){
    	mid=(l+r)/2;
    	if(check(b[mid])==1){
    		ans=b[mid];
    		l=mid+1;
    		//
    		//printf("%d %d  1\n",l,r);
    		//
    	}
    	else{
    		r=mid-1;
    		//
    		//printf("%d %d  -1\n",l,r);
    		//
    	}
    }
    printf("%d\n",ans);
    return 0;
}