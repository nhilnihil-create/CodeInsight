#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dat(n+1);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        if(a==1||b==1||a==n||b==n){
            dat[a].push_back(b);
            dat[b].push_back(a);
        }
    }
    for(int p:dat[1]){
        if(dat[p].size()>=2){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}