#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=100010;
typedef long long ll;
int a[N];ll b[N];
int p[N],ip[N];int vis[N];
vector<int> vec[N];int cnt;

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n,m;ll K;
	register int i,j,x,y;
	scanf("%d",&n);
	rep(i,1,n)	scanf("%d",&a[i]);
	scanf("%d%lld",&m,&K);
	for(i=n;i>=2;i--)	a[i]-=a[i-1];
	rep(i,1,n)	ip[i]=i;
	rep(i,1,m){
		scanf("%d",&x);
		swap(ip[x],ip[x+1]);
	}
	rep(i,1,n)	p[ip[i]]=i;
	rep(i,2,n){
		cnt++;
		for(x=i;!vis[x];x=p[x]){
			vis[x]=1;vec[cnt].pb(x);//id[x]=cnt;f[x]=tmp;tmp++;
		}
		//c[cnt]=tmp;
	}
	rep(i,1,cnt) if((int)vec[i].size()){
		rep(j,0,(int)vec[i].size()-1){
			x=vec[i][j];y=vec[i][(j+K)%vec[i].size()];
			b[y]=a[x];
		}
	}
	b[1]=a[1];
	rep(i,1,n)	b[i]+=b[i-1];
	rep(i,1,n)	printf("%lld.0\n",b[i]);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	