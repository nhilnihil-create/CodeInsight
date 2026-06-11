#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++) 
#define ltype int
#define rep(i,j,k) for(ltype (i)=(j);(i)<=(k);(i)++)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
const int inf=0x3f3f3f3f,
mod=1000000007;
const double pi=3.1415926535897932,
eps=1e-6;
int n,t,a[100005],suf[100005],prf,cnt;
int main(){
    scanf("%d%d",&n,&t);
    rep(i,1,n) scanf("%d",a+i);
    for(int i=n;i>=1;i--) suf[i]=max(a[i],suf[i+1]);
    rep(i,1,n) {
        if(suf[i]-a[i]>prf) prf=suf[i]-a[i],cnt=1;
        else if(suf[i]-a[i]==prf) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}