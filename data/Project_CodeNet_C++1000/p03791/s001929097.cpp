#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
const int P=1000000007;
int a[N],n;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    int ans=1;
    int need=1;
    int pre=0;
    rep(i,1,n){
        ans=ans*1ll*(n-pre-(n-i))%P;
        if(a[i]<need)++pre;
        else need+=2;
    }
    printf("%d\n",ans);
    return 0;
}


