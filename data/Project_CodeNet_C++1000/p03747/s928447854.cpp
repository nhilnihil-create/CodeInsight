#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,L,T;
int a[N],x[N],w[N];
int main()
{
    scanf("%d%d%d",&n,&L,&T);
    int rk=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&w[i]);
        if(w[i]==1){
            x[i]=(a[i]+T)%L;
            rk+=(a[i]+T)/L;
        }
        else{
            x[i]=(a[i]-T)%L;
            rk+=(a[i]-T)/L;
            if(x[i]<0){
                x[i]+=L;
                rk--;
            }
        }
    }
    rk=(rk%n+n)%n;
    sort(x,x+n);
    for(int i=rk;i<n;i++)
        printf("%d\n",x[i]);
    for(int i=0;i<rk;i++)
        printf("%d\n",x[i]);
}
