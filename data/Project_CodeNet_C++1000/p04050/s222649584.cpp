// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
 
const int inf = 1 << 30;
 
int n,m;
int a[100005];
int b[200005],c[100005],cnt=0;
 
void s0(){
	int s=n;
	b[++cnt]=1;-- s;
	for(int i=1;i<=m-1;i++)b[++cnt]=a[i], s -= a[i];
	if(s==0)return ;
	-- s; s>>=1;
	
	for(int i=1;i<=s/2;i++)b[++cnt]=2;b[++cnt]=1;
	for(int i=s/2+1;i<=s;i++)b[++cnt]=2;
} // 1 a[1] .. a[m-1] 2 2 .. 2 1 2 .. 2 2
 
void s1(){
	for(int i=1;i<=a[1]/2;i++)b[++cnt]=2;
	for(int i=2;i<=m;i++)b[++cnt]=a[i];
	b[++cnt]=1;
} // 2 2 .. 2 a[2] .. a[m] 1
 
void s2(){
	b[++cnt]=a[1]+1;
	for(int i=2;i<m;i++)b[++cnt]=a[i];
	for(int i=1;i<=a[m]/2;i++)b[++cnt]=2;
} // a[1]+1 a[2] .. a[m] 2 2 .. 2 2
 
int main(){
	int od=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]), od += (a[i]&1);
	if(od>2)return puts("Impossible"),0;
	
	int cnt2=0;
	for(int i=1;i<=m;i++)
		if(a[i]&1)c[++ cnt2]=i;
	if(cnt2>=1)swap(a[1],a[c[1]]);
	if(cnt2>=2)swap(a[m],a[c[2]]);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
		
	if(cnt2==0)s0();
	if(cnt2==1)s1();
	if(cnt2==2)s2();
	
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",b[i]);puts("");
 
	return 0;
}