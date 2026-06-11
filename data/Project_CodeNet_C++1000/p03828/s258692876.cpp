#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

    int n;
    cin>>n;

    ll ans=1;
    int count[n+1]={};
    int k=0;
    for(int i=2;i<=n;i++){
        k=i;
        for(int j=2;j<=i;j++){
            while(k%j==0){
                k/=j;
                count[j]++;
            }
        }
        count[k]++;
    }
    
    for(int i=2;i<=n;i++)ans=(ans*(count[i]+1))%mod;
    cout<<ans<<endl;

    return 0;
}
