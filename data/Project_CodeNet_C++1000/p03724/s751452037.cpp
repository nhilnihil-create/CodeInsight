#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>cnt(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        cnt[a-1]++;
        cnt[b-1]++;
    }
    bool ans=true;
    rep(i,n){
        if(cnt[i]!=0){
            if(cnt[i]%2!=0)ans=false;
        }
    }
    cout<<(ans==true? "YES" : "NO")<<endl;
}