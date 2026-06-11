
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define pb push_back 
using namespace std;

int ans[100],len,l,r,y,cnt,mid,sum;
char ok;
long long x;

int main(){
	l=1;r=9;y=11;cnt=0;
	x=1;
	while (1) {
		printf("? %lld\n",x);
		fflush(stdout);
		cin>>ok;
		if (ok=='N')break;
		len++;
		if (len>11) break;
		x*=10;
	}
	x=1;
	if (len>11) {
		while (1) {
			printf("? ");
			rep(i,0,x) printf("9");
			printf("\n");
			fflush(stdout);
			cin>>ok;
			if (ok=='Y') break;
			x++;
		}
		printf("! 1");
		rep(i,1,x) printf("0");
		fflush(stdout);
		return 0;	
	}
	while (1){
		sum++;
		mid=(l+r)>>1;
		printf("? ");
		rep(i,1,cnt+1) printf("%d",ans[i]);
		printf("%d",mid);
		rep(i,0,y) printf("9");
		printf("\n");
		fflush(stdout);
		cin>>ok;
		if (ok=='Y') {
			r=mid;
			if (l==r) {
				cnt++;ans[cnt]=l;y--;l=0;r=9;sum=0;
				if (cnt==len) break;
			}
		}else{
			l=mid+1;
		}
	}	
	printf("! ");
	rep(i,1,cnt+1) printf("%d",ans[i]);
	fflush(stdout);
	return 0;
}