#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int m;cin>>m;
    ll p[m],x[m];
    for(int j=1;j<=m;j++){
        cin>>p[j]>>x[j];
        cout<<sum-a[p[j]]+x[j]<<"\n";
    }
    
    
    return 0;
}