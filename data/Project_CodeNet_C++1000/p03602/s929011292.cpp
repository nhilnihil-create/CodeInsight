#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
main(){
    bool flag=true,flag2;
    int n;
    ll ans=0;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ans+=a[i][j];
            flag2=true;
            for(int k=0;k<n;k++){
                if(a[i][k]>a[i][j]+a[j][k])flag=false;
                if(flag2&&i!=k&&j!=k&&a[i][j]==a[i][k]+a[j][k]){
                    ans-=a[i][j];
                    flag2=false;
                }
            }
        }
    }

if(flag)cout<<ans<<endl;
else cout<<-1<<endl;
}