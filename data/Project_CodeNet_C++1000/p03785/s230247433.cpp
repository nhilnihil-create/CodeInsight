#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,c,k;
    cin>>n>>c>>k;
    vector<int>t(n);
    rep(i,n)cin>>t[i];
    sort(t.begin(),t.end());
    int ans=1,cnt=1,start=t[0];
    for(int i=1; i<n; ++i){
        if(t[i]<=start+k){
            if(cnt<c)cnt++;
            else cnt=1,ans++,start=t[i];
        }
        else cnt=1,ans++,start=t[i];
    }
    cout<<ans<<endl;
    return 0;
}