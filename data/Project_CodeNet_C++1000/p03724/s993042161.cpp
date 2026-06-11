#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, m;
    cin>>n>>m;
    map<int, int> mp;
    rep(i, m){
        int a, b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }
    bool ok = true;
    for(auto p : mp){
        if(p.second%2) ok = false;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}