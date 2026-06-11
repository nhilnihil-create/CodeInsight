#include <bits/stdc++.h>
#define il inline
#define RG register
#define ll long long
#define N (100005)

using namespace std;

ll tim[N],del[N],dep[N],res,ans;
int id[N],a[N],n,m;

il int gi(){
	RG int x=0,q=1; RG char ch=getchar();
	while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if (ch=='-') q=-1,ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return q*x;
}

il int cmp(const int &a,const int &b){ return dep[a]>dep[b]; }

il void work(){
	for (RG int x=1;x<=m;++x){
		RG ll dep=0;
		for (RG int i=2,cur,now;i<=n;++i){
			cur=a[i]-a[i-1]; if (cur<0) cur+=m;
			now=a[i]-x; if (now<0) now+=m; ++now;
			dep+=min(cur,now);
		}
		ans=min(ans,dep);
	}
	cout<<ans; return;
}

int main(){
	n=gi(),m=gi(),ans=1LL<<60;
	for (RG int i=1;i<=n;++i) a[i]=gi();
	if (1LL*n*m<=100000000) work(),exit(0);
	for (RG int i=2;i<=n;++i)
		if (a[i]>=a[i-1]){
			tim[a[i-1]]++,tim[a[i]+1]--;
			del[a[i-1]]-=a[i-1],del[a[i]+1]+=a[i-1];
		} else{
			tim[a[i-1]]++,del[a[i-1]]-=a[i-1];
			tim[1]++,tim[a[i]+1]--;
			del[1]+=m-a[i-1],del[a[i]+1]-=m-a[i-1];
		}
	for (RG int i=1;i<=m;++i)
		tim[i]+=tim[i-1],del[i]+=del[i-1],dep[i]=1LL*i*tim[i]+del[i],id[i]=i;
	sort(id+1,id+m+1,cmp);
	for (RG int j=1,sz=min(2000,m),x;j<=sz;++j){
		x=id[j]; RG ll res=0;
		for (RG int i=2,cur,now;i<=n;++i){
			cur=a[i]-a[i-1]; if (cur<0) cur+=m;
			now=a[i]-x; if (now<0) now+=m; ++now;
			res+=min(cur,now);
		}
		ans=min(ans,res);
	}
	cout<<ans; return 0;
}
