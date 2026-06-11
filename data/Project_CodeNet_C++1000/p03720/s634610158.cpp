#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(n+1,0);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }

    for(int i=1;i<=n;i++) cout<<cnt[i]<<"\n";
    return 0;
}