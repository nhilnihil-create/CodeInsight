#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;

int n;
int a[MAXN*2];

bool check(int x){
    for(int i=0;i<n-1;i++){
        if(a[n+i]>=x&&a[n+i+1]>=x) return 1;
        if(a[n-i]>=x&&a[n-i-1]>=x) return 1;
        if(a[n+i]<x&&a[n+i+1]<x) return 0;
        if(a[n-i]<x&&a[n-i-1]<x) return 0;
    }
    return a[1]>=x;
}

int main(){

	scanf("%d",&n);
	for(int i=1;i<2*n;i++) scanf("%d",&a[i]);
	int l=1,r=2*n;
	while(r-l>1){
	    int mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
	}
	printf("%d",l);

	fclose(stdin);
	fclose(stdout);
}
