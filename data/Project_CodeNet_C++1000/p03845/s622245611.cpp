#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef long double ld;

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        vector<int> a(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        cin>>m;
        
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ll l=(sum-a[x-1])+y;
            cout<<l<<endl;
        }
    }
}