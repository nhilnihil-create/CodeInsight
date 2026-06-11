#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll INF=1e10;
int main(){
    int n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            bool need=true;
            for(int k=0;k<n;k++){
                if(k==i || k==j) continue;
                if(a[i][j]>a[i][k]+a[k][j]){
                    cout<<-1<<endl;
                    return 0;
                }
                else if(a[i][j]==a[i][k]+a[k][j]){
                    need=false;
                }
            }
            if(need) res+=a[i][j];
        }
    }
    cout<<res<<endl;
    
    return 0;
}