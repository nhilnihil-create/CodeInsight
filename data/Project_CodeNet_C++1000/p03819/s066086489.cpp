#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int m,n;
typedef pair<int,int> Pair;
Pair p[300005];
int sum[400005],add[400005];

void update(int o,int l,int r,int x,int y,int a){
	if(l>=x&&r<=y){
		sum[o]+=a*(r-l);
		add[o]+=a;
	}else{
		int mid=l+r>>1;
		if(x<mid)update(o<<1,l,mid,x,y,a);
		if(y>mid)update(o<<1|1,mid,r,x,y,a);
		sum[o]=sum[o<<1]+sum[o<<1|1]+add[o]*(r-l);
	}
}

int query(int o,int l,int r,int x,int a){
	if(r-l==1){
		return sum[o]+a;
	}else{
		int mid=l+r>>1;
		if(x<mid)return query(o<<1,l,mid,x,a+add[o]);
		else return query(o<<1|1,mid,r,x,a+add[o]);
	}
}

bool comp(Pair a,Pair b){
	return a.second-a.first<b.second-b.first;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].first,&p[i].second);
    sort(p+1,p+n+1,comp);
    int i=1;
    for(int d=1;d<=m;d++){
        while(i<=n&&p[i].second-p[i].first+1<d){
            update(1,1,m+1,p[i].first,p[i].second+1,1);
            i++;
        }
        int ans=n-i+1;
        for(int k=d;k<=m;k+=d)
            ans+=query(1,1,m+1,k,0);
        printf("%d\n",ans);
    }
    return 0;
}