#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    n*=2;
    vector<int>l(n);
    rep(i,n)cin>>l[i];
    sort(l.rbegin(),l.rend());
    int ans=0;
    for(int i=0; i<n-1; i+=2){
        ans+=l[i+1];
    }
    cout<<ans<<endl;
    return 0;
}