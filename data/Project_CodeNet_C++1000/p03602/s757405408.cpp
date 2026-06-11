#include<bits/stdc++.h>

using namespace std;

#define ll long long 

int main() {
    int n;
    cin>>n;
    ll a[n][n]; ll d[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }
    
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    int flag=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j]!=d[i][j]) flag=1;
        }
    }

    if(flag) cout<<-1<<endl;
    else {
        ll ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int mask=0;
                for(int k=0;k<n;k++) {
                    if(k!=i && k!=j) {
                        mask|=(d[i][j]==d[i][k]+d[k][j]);
                    } 
                }
                if(!mask) ans+=d[i][j];
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;;
}