#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define top 2000000000
#define ll long long
using namespace std;
int n, m, k, l1, l2, a[N], b[N], x, y, p1[N], p2[N], pos1[N], pos2[N], ans[N], now, x1, x2, L1, L2, R1, R2;
ll L, R, mid, sum;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	l1=l2=0;
	for(int i=1; i<=n; i++){
		scanf("%d%d", &x, &y);
		if(y==1){a[++l1]=x; pos1[l1]=i;}
		else{b[++l2]=x; pos2[l2]=i;}
	}
	for(int i=1; i<=l1; i++)p1[i]=(a[i]+k)%m;
	for(int i=1; i<=l2; i++)p2[i]=(b[i]-k%m+m)%m;
	if(!l1||!l2){
		for(int i=1; i<=l1; i++)ans[pos1[i]]=p1[i];
		for(int i=1; i<=l2; i++)ans[pos2[i]]=p2[i];
		for(int i=1; i<=n; i++)printf("%d\n", ans[i]);
		return 0;
	}
	k<<=1;
	for(int i=1; i<=l1; i++)a[l1+i]=a[i]+m;
	for(int i=1; i<=l2; i++)b[l2+i]=b[i]+m;
	now=l2*2;
	for(int i=l1; i; i--){
		while(now>1&&b[now-1]>a[i])now--;
		x=k-(b[now]-a[i]); if(x<0){ans[pos1[i]]=p1[i]; continue;}
		L=0; R=top;
		while(L<R){
			mid=(L+R)>>1; if(L==R-1)mid++; sum=0;
			sum+=(ll)m*((mid+1)/(2*l1))+(ll)m*(mid/(2*l2));
			x1=((mid+1)/2)%l1; x2=(mid/2)%l2;
			L1=(i-x1+l1-1)%l1+1; R1=i;
			L2=(now-1)%l2+1; R2=(L2+x2-1)%l2+1;
			sum+=L1<=R1?a[R1]-a[L1]:m+a[R1]-a[L1];
			sum+=L2<=R2?b[R2]-b[L2]:m+b[R2]-b[L2];
			if(sum<=x)L=mid; else R=mid-1;
		}
		if(L&1)ans[pos1[i]]=p1[(i-((L+1)/2)%l1+l1-1)%l1+1];
		else ans[pos1[i]]=p2[((now-1)%l2+1+(L/2)%l2-1)%l2+1];
	}
	now=1;
	for(int i=1; i<=l2; i++){
		while(now<l1*2&&a[now+1]<b[l2+i])now++;
		x=k-(b[l2+i]-a[now]); if(x<0){ans[pos2[i]]=p2[i]; continue;}
		L=0; R=top;
		while(L<R){
			mid=(L+R)>>1; if(L==R-1)mid++; sum=0;
			sum+=(ll)m*(mid/(2*l1))+(ll)m*((mid+1)/(2*l2));
			x1=(mid/2)%l1; x2=((mid+1)/2)%l2;
			R1=(now-1)%l1+1; L1=(R1-x1+l1-1)%l1+1;
			L2=i; R2=(i+x2-1)%l2+1;
			sum+=L1<=R1?a[R1]-a[L1]:m+a[R1]-a[L1];
			sum+=L2<=R2?b[R2]-b[L2]:m+b[R2]-b[L2];
			if(sum<=x)L=mid; else R=mid-1;
		}
		if(L&1)ans[pos2[i]]=p2[(i+((L+1)/2)%l2-1)%l2+1];
		else ans[pos2[i]]=p1[((now-1)%l1+1-(L/2)%l1+l1-1)%l1+1];
	}
	for(int i=1; i<=n; i++)printf("%d\n", ans[i]);
	return 0;
}