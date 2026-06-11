#include <bits/stdc++.h>
using namespace std;

const int N=300005;

int n,m;

struct Seg{
	int l,r,len;
	void readin(){
		scanf("%d%d",&l,&r);
		len=r-l+1;
	}
}a[N];

bool cmp(Seg x,Seg y){return x.len<y.len;}

struct Tree{
	
	int c[N];
	
	void updata(int x,int v){
		for(;x<=m;x+=x&(-x)) c[x]+=v;
	}
	
	int query(int x){
		int ret=0;
		for(;x>0;x-=x&(-x)) ret+=c[x];
		return ret;
	}
}T;

void work()
{
	int k=1; 
    for(int i=1,k=1;i<=m;i++)
    {
    	for(;k<=n&&a[k].len<i;k++) T.updata(a[k].l,1),T.updata(a[k].r+1,-1);
        int ans=n-k+1; 
        for(int j=i;j<=m;j+=i) ans+=T.query(j);
        printf("%d\n",ans);
    }
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i].readin();
	sort(a+1,a+1+n,cmp);
}

int main()
{
	init();
	work();
	return 0;
}