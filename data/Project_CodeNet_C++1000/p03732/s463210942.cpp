#include <bits/stdc++.h>
using namespace std;
const int N=2000;
map<int,int>mp[200]; ///前i个物品用背包w能获取的最大价值

int main() {

    int n,W;
    cin>>n>>W;
    int w,v;
    mp[0][0]=0;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        for(auto p:mp[i]){
            mp[i+1][p.first]=max(mp[i][p.first],mp[i+1][p.first]);
            if(p.first+w<=W){
                mp[i+1][p.first+w]=max(mp[i+1][p.first+w],mp[i][p.first]+v);
            }
        }
    }
    int ans=0;
    for(auto p:mp[n]){
        ans=max(ans,p.second);
    }
    cout<<ans;
    return 0;
}


