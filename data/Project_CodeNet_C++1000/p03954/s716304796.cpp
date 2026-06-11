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
int n,n2,a[200005];bool p[200005];
int mid(int a,int b,int c){
    int m=max(a,max(b,c)),k=min(a,min(b,c));
    return a+b+c-m-k;
}
bool check(int x){
    rep(i,1,n2) p[i]=a[i]>=x;
    if(p[n-1]==p[n]||p[n]==p[n+1]) return p[n];
    int l=n-1,r=n+1;
    while(l>1&&p[l-1]!=p[l]) l--;
    while(r<n2&&p[r+1]!=p[r]) r++;
    if(r-l+1==n2) return p[l];
    if(((r-l+1)&1)==1) return p[l];
    if(abs(n-l)<abs(n-r)) return p[l];
    return p[r];
}
int main()
{
    scanf("%d",&n);n2=2*n-1;
    rep(i,1,n2) scanf("%d",a+i);
    int l=1,r=n2,ans=0;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}