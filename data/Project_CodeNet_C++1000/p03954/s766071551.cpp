#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=2e5+10;
int n,a[N],b[N];

bool check(int x){
	rep (i,1,2*n-1) b[i]=a[i]>x;
	int m=n,l=m,r=m;
	while (l>1&&b[l-1]!=b[l]) l--;
	while (r<2*n-1&&b[r+1]!=b[r]) r++;
	if (l==m||r==m) return b[m];
	if (b[l]==b[r]) return b[l];
	return l>2*n-r?b[l]:b[r];
}

int main(){
	scanf("%d",&n);
	rep (i,1,2*n-1) scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while (l<=r){
		int mid=l+r>>1;
		if (!check(mid)) r=mid-1; else l=mid+1;
	}
	printf("%d\n",r+1);
	return 0;
}