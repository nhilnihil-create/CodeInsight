#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
ll sum[maxn],ans,wdc;
int num[maxn],a[maxn];
int i,j,k,l,t,n,m,x,y;
void change(int l,int r,int v){
    sum[l]+=(ll)v;
    sum[r+1]-=(ll)v;
}
void modify(int l,int r,int v){
    num[l]+=v;
    num[r+1]-=v;
}
int main(){
    scanf("%d%d",&n,&m);
    fo(i,1,n) scanf("%d",&a[i]);
    fo(i,1,n-1){
        x=a[i];y=a[i+1];
        if (x==y) continue;
        if (x<y){
            change(1,x,y-x);
            change(y+1,m,y-x);
            change(x+1,y,y+1);
            modify(x+1,y,-1);
        }
        else{
            change(y+1,x,y+m-x);
            change(x+1,m,y+m+1);
            modify(x+1,m,-1);
            change(1,y,y+1);
            modify(1,y,-1);
        }
    }
    ans=100000000000000;
    fo(i,1,m){
        sum[i]+=sum[i-1];
        num[i]+=num[i-1];
        wdc=sum[i]+(ll)num[i]*i;
        ans=min(ans,wdc);
    }
    printf("%lld\n",ans);
}