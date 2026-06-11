
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=510;
struct fk{int x,id;}q[N];
int n,a[N*N],cnt[N],flag;
bool cmp(fk a,fk b){return a.x<b.x;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&q[i].x),q[i].id=i;
    sort(q+1,q+n+1,cmp);
    for(int i=1;i<=n;i++){
        int id=q[i].id;
        a[q[i].x]=id;++cnt[id];
        for(int j=1;j<q[i].x;j++){
            if(cnt[id]==id)break;
            if(!a[j])a[j]=id,++cnt[id];
        }
        if(cnt[id]<id)flag=1;
    }
    if(flag){puts("No");return 0;}
    flag=0;
    for(int i=n;i>=1;i--){
        int id=q[i].id;
        for(int j=n*n;j>q[i].x;j--){
            if(cnt[id]==n)break;
            if(!a[j])a[j]=id,++cnt[id];
        }
        if(cnt[id]<n)flag=1;
    }
    if(flag){puts("No");return 0;}
    puts("Yes");
    for(int i=1;i<=n*n;i++)printf("%d ",a[i]);
    puts("");
}
