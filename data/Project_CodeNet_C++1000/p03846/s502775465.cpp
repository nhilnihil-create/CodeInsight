#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef long double ld;

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll MOD=1e9+7;
        map<int,int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        if(n%2==0){
            for(auto j: a){
                if(j.first%2==0 || j.second!=2){
                    cout<<0;
                    return 0;
                }
            }
            ll ans=1;
            for (int i=0; i<n/2; i++) {
                ans *= 2;
                ans %= MOD;
            }
            cout<<ans;
        }
        else{
            for(auto j: a){
                if(j.first==0 && j.second!=1){
                    cout<<0;
                    return 0;
                }
                else{
                    if(j.first%2!=0 && j.second!=2){
                    cout<<0;
                    return 0;
                }
                }
            }
            ll ans=1;
            for (int i=0; i<n/2; i++) {
                ans *= 2;
                ans %= MOD;
            }
            cout<<ans;
        }
    }
}