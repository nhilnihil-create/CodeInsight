#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int t[105];
int m;
int p[105],x[105];
int sum;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>p[i]>>x[i];
        cout<<sum-t[p[i]-1]+x[i]<<endl;
    }
    
    
}
