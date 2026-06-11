#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;

int count(int x) {
    if (mp.count(x) == 0) return 0;
    return mp[x];
}    

int main() {
    int n;cin>>n;

    for(int i=0;i<n;i++){
        int a;cin>>a;mp[a]++;
    }
    int ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int x;
        x=it->first;
        ans=max(ans,count(x)+count(x-1)+count(x+1));
        ans=max(ans,count(x-1)+count(x-2)+count(x));
        ans=max(ans,count(x+1)+count(x)+count(x+2));
    }
    cout<<ans<<endl;
}