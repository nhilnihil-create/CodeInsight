#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N=100005;
int X[N],cha[N],p[N],cnt[N];
int a[N],dfn[N],c[N];
vector<long long> O[N];
int n,m,k,num,s;
void find(int x,int len){
    dfn[x]=len,c[x]=num;
    cnt[num]++;
    O[num].push_back(x);
    if(!c[p[x]]) find(p[x],len+1);
}
signed main (){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    scanf("%lld",&X[i]),cha[i-1]=X[i]-X[i-1];
    for(int i=1;i<=n;i++) 
    p[i]=i;
    
	scanf("%lld%lld",&m,&k);
    for(int i=1;i<=m;i++)
    scanf("%lld",&a[i]),
	swap(p[a[i]],p[a[i]-1]);
	
    for(int i=1;i<=n;i++)if(!dfn[i]) 
	num++,find(i,0);
    s=X[1],printf("%.1lf\n",1.0*s);
    for(int i=1;i<n;i++){
    	int pos=(dfn[i]+k)%O[c[i]].size();
		printf("%.1lf\n",1.0*(s+=cha[O[c[i]][pos]]));
	}
}