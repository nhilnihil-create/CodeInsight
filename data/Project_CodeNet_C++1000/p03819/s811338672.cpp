#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
int n,m,i,j,l[1000005],r[1000005],ans[1000005],p1,p2,a[1000005],sum,top,flag;
struct nyh{
	int x,y,z,id;
}o[5000005];
bool cmp(nyh u,nyh v){
	return u.x<v.x||u.x==v.x&&u.id<v.id;
}
void xtree(int u,int v,int w){
	int mid=(u+v>>1);
	if(u==v){
		a[w]+=p2;
		return;
	}
	if(p1<=mid){
		a[(w<<1)|1]+=p2;
		xtree(u,mid,w<<1);
	}
	else
		xtree(mid+1,v,(w<<1)|1);
}
void ytree(int u,int v,int w){
	int mid=(u+v>>1);
	sum+=a[w];
	if(u==v)
		return;
	if(p1<=mid) ytree(u,mid,w<<1);
	else ytree(mid+1,v,(w<<1)|1);
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++){
		l[i]=read();r[i]=read();
		top++;
		o[top].x=1;
		o[top].y=r[i];
		o[top].z=1;
		top++;
		o[top].x=l[i]+1;
		o[top].y=r[i];
		o[top].z=-1;
	}
	
	for(i=1;i<=m;i++)
		ans[i]=n;
	flag=min(100,(int)sqrt(m));
	for(i=2;i<=flag;i++)
		for(j=1;j<=n;j++)
			if(r[j]/i==(l[j]-1)/i)
				ans[i]--;
	for(i=flag+1;i<=m;i++)
		for(j=0;j<m;j+=i){
			top++;
			o[top].x=j+1;
			o[top].id=i;
			if(j+i-1<=m)
				o[top].y=j+i-1;
			else{
				o[top].y=m;
				break;
			}
		}		
	sort(o+1,o+top+1,cmp);
	for(i=1;i<=top;i++){	
		if(o[i].z!=0){
			p1=o[i].y;
			p2=o[i].z;
			xtree(1,m,1);
		}
		else{
			p1=o[i].y;sum=0;
			ytree(1,m,1);
			ans[o[i].id]-=sum;
		}
	
	}
	for(i=1;i<=m;i++)
		pus(ans[i],2);
	return 0;
}