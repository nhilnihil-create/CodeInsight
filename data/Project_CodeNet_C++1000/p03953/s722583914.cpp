#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
ll x[maxn],d[maxn],c[maxn];
int ans[maxn],now[maxn],o[maxn],sta[maxn];
int i,j,l,t,n,m,top;
ll k;
void mult(int *a,int *b,int *c){
    int i;
    fo(i,1,n) o[i]=a[b[i]];
    fo(i,1,n) c[i]=o[i];
}
int main(){
    scanf("%d",&n);
    fo(i,1,n){
        scanf("%lld",&x[i]);
        d[i]=x[i]-x[i-1];
        ans[i]=now[i]=i;
    }
    scanf("%d%lld",&m,&k);
    fo(i,1,m){
        scanf("%d",&t);
        swap(now[t],now[t+1]);
    }
    top=0;
    while (k){
        sta[++top]=k%2;
        k/=2;
    }
    while (top){
        mult(ans,ans,ans);
        if (sta[top--]) mult(ans,now,ans);
    }
    fo(i,1,n) c[i]=d[ans[i]];
    fo(i,1,n) x[i]=x[i-1]+c[i];
    fo(i,1,n) printf("%lld.0\n",x[i]);
}