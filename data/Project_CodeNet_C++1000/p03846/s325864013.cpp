#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1000000007;

int main(){
    int n;cin>>n;
    int flag=1;
    ll ans=1;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    if(n%2==0){
        int check=1;
        for(int i=0;i<n;i+=2){
            ans*=2;ans%=MOD;
            if(check==a[i] & check==a[i+1]) check+=2;
            else flag=0;
        }
    }
    else{
        if(a[0]!=0) flag=0;
        int check=2;
        for(int i=1;i<n;i+=2){
            ans*=2;ans%=MOD;
            if(check==a[i] & check==a[i+1]) check+=2;
            else flag=0;
        }
    }
    if(flag) cout<<ans<<endl;
    else cout<<0<<endl;
}