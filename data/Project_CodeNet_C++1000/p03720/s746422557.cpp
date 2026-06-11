#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m;
int ans[55];
int a,b;
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ans[a]++;
        ans[b]++;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    
}
