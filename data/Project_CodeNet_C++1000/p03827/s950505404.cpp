#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int n;cin>>n;
    string s;cin>>s;
    int x=0,ans=0;
    for(int i=0;i<s.length();i++){
        if (s[i]=='I')x++;
        if (s[i]=='D')x--;
        ans = max(ans,x);
    }
    cout << ans;
    return 0;
}