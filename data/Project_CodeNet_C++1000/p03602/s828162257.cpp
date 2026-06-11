#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=305;
int n,a[max_n][max_n];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool f=false;
            for(int k=1;k<=n;k++){
                if(k==i||k==j)continue;
                if(a[i][k]+a[k][j]<a[i][j])return printf("-1\n"),0;
                else if(a[i][k]+a[k][j]==a[i][j])f=true;
            }
            if(f==false)ans+=a[i][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}