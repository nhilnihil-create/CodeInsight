#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=1e9;
    for(char i='a'; i<='z'; ++i){
        if(s.find(i)==s.npos)continue;
        int cnt=0,mx=0;
        rep(j,n){
            if(s[j]==i)cnt=0;
            else mx=max(mx,++cnt);
        }
        ans=min(ans,mx);
    }
    cout<<ans<<endl;
}
