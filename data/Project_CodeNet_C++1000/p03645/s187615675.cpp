#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>to[n];
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int u:to[0]){
        if(count(to[u].begin(),to[u].end(),n-1)!=0){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}