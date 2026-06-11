#include <cstdio>
#include <algorithm>
#define LHX_BAOLING {puts("Impossible"); return 0;}
using namespace std;
const int N=100010,M=110;
int n,m;
int a[M];
int p1,p2;
int b[N],bcnt;
void readData(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
}
bool judge(){
	p1=p2=-1;
	for(int i=1;i<=m;i++)
		if(a[i]&1){
			if(p1==-1)
				p1=i;
			else if(p2==-1)
				p2=i;
			else return false;
		}
	return true;
}
void construct(){
	if(p1!=-1){
		swap(a[1],a[p1]);
		p1=1;
	}
	if(p2!=-1){
		swap(a[p2],a[m]);
		p2=m;
	}
	for(int i=1;i<=m;i++) printf("%d ",a[i]);
	puts("");
	if(m==1){
		if(a[1]&1){
			if(a[1]-1)
				b[++bcnt]=a[1]-1;
			b[++bcnt]=1;
		}
		else{
			if(a[1]-2)
				b[++bcnt]=a[1]-2;
			b[++bcnt]=2;
		}
	}
	else{
		if(a[1]&1){
			if(a[1]-1)
				b[++bcnt]=a[1]-1;
		}
		else{
			if(a[1]-2)
				b[++bcnt]=a[1]-2;
			b[++bcnt]=1;
		}
		for(int i=2;i<m;i++)
			b[++bcnt]=a[i];
	}
	int sum=0;
	for(int i=1;i<=bcnt;i++) sum+=b[i];
	if(n-sum){
		int x=n-sum;
		if(x&1){
			if(x-1)
				b[++bcnt]=x-1;
			b[++bcnt]=1;
		}
		else
			b[++bcnt]=x;
	}
	printf("%d\n",bcnt);
	for(int i=1;i<=bcnt;i++) printf("%d ",b[i]);
	puts("");
}
int main(){
	readData();
	if(!judge())
		LHX_BAOLING;
	construct();
	return 0;
}
