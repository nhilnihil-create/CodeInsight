#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m;
int x[55],y[55],a[55],b[55];
int ans[55];
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        int cnt=1000000000;
        for(int j=0;j<m;j++){
            if(cnt>abs(x[i]-a[j])+abs(y[i]-b[j])){
                ans[i]=j+1;
                cnt=abs(x[i]-a[j])+abs(y[i]-b[j]);
            }
        }
        cout<<ans[i]<<endl;
    }
    
    
}
