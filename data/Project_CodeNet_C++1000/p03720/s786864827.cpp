#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> field(n+1);
    rep(i,m){
        int a,b;
        cin>>a>>b; a--;b--;
        field[b].push_back(a);
        field[a].push_back(b);
    }
    rep(i,n){
        cout<<field[i].size()<<endl;
    }
}