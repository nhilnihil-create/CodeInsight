#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n,a;
vector<int> E[100009];

int dfs(int x){
    vector<int> vec;
    rep(i,E[x].size()){
        vec.push_back(dfs(E[x][i]));
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int re=0;
    rep(i,vec.size())re=max(re,vec[i]+i+1);
    return re;
}

int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>a;
        E[a].push_back(i);
    }
    cout<<dfs(1)<<endl;
}