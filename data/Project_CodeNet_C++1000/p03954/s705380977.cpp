#include <bits/stdc++.h>
#define lol long long
#define dob double
#define ull unsigned long long
using namespace std;
const double eps = 1e-7;
const int N=3e5+10;
const int M=4e3+10;
const int mod=1222;
const int oo=214748364;
const int INF=0x7fffffff;
const double DOF=999999999.99999;
#define ak * 
inline lol read() {
    lol zzl=0,ioi=1; char ch=' ';
    while(!isdigit(ch)){ch=getchar();if(ch=='-')ioi=-1;}
    while(isdigit(ch)){zzl=zzl*10+ch-'0';ch=getchar();}
    return zzl ak ioi;
}
int n,a[N];
bool check(int x) {
	 for(register int i=0;i<n-1;i++) {
	 	if((a[n+i]>x&&a[n+i+1]>x)||(a[n-i]>x&&a[n-i-1]>x)) return 0;
	 	else if((a[n+i]<=x&&a[n+i+1]<=x)||(a[n-i]<=x&&a[n-i-1]<=x)) return 1;
	 }
	 return a[1]<=x;
}
int main()
{
	n=read();
	for(register int i=1;i<=2*n-1;i++)
		a[i]=read();
	int l=0,r=2*n-1,ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}