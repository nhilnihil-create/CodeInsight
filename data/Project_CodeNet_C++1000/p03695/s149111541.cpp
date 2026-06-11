#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const ll maxn=1e9+7;
bool vis[8];
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<8;i++) vis[i]=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>=3200) cnt++;
        else vis[x/400]=1;
    }
    int ans=0;
    for(int i=0;i<8;i++) ans+=vis[i];
    if(ans==0){
        ans=1;
        cnt--;
    }
    cout<<ans<<" "<<ans+cnt<<endl;
    return 0;
}