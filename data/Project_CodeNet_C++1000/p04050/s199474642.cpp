#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
int fa[MAXN],a[MAXN],b[MAXN];
int n,m;
int main(){
    SF("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=m;i++){
        SF("%d",&a[i]);
        if(a[i]%2==1)
            cnt++;
    }
    if(m==1){
        PF("%d\n",a[1]);    
        if(a[1]==1)
            PF("1\n1");
        else
            PF("2\n%d %d",a[1]-1,1);
        return 0;
    }
    if(cnt>2){
        PF("Impossible");
        return 0;   
    }
    for(int i=1;i<=m;i++)
        if(a[i]%2==1){
            swap(a[i],a[1]);
            break;
        }
        
    for(int i=m-1;i>1;i--)
        if(a[i]%2==1){
            swap(a[i],a[m]);
            break;  
        }
    for(int i=1;i<=m;i++)
        PF("%d ",a[i]);
    b[1]=a[1]+1;
    for(int i=2;i<m;i++)
        b[i]=a[i];
    b[m]=a[m]-1;
    
    if(b[m]==0)
        m--;
    PF("\n%d\n",m);
    for(int i=1;i<=m;i++)
        PF("%d ",b[i]);
}