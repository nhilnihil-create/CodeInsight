#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100001;
typedef long long ll;
/*void new_arr(ll **&a,int m,int n){
a=new ll*[m+1];
for(int i=0;i<=m;i++)
    a[i]=new ll[n+1];
for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    scanf("%lld",a[i]+j);
}*/
int main()
{
    int n;
    cin>>n;
    ll map[301][301];
    //new_arr(map,n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        scanf("%lld",&map[i][j]);
    ll ans=0,flg=0;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        ll ans1=0x3f3f3f3f;
        for(int k=1;k<=n;k++){
            if(k==i||k==j)continue;
            ans1=min(map[i][k]+map[k][j],ans1);
        }
            if(ans1==map[i][j])continue;
            if(ans1>map[i][j]){ans+=map[i][j];//cout<<map[i][j]<<endl;
            }
            if(ans1<map[i][j])flg=1;
    }
    if(flg)cout<<-1<<endl;
    else cout<<ans<<endl;
   // delete map;
}
