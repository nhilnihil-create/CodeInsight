#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll n,k,res=0;
vector<int> a(100000);
vector<vector<int>> g(100000);

int dfs(int node){
    if(g[node].size()==0){
        // leaf
        if(k==1){
            if(a[node]!=0){
                a[node]=0;
                res++;
            }
            return 0;
        }
        return 1;
    }
    int ma=0;
    for(int i=0;i<(int)g[node].size();i++){
        int next=g[node][i];
        ma=max(ma,dfs(next));
    }
    ma++;
    if(ma==k){
        if(a[node]!=0){
            a[node]=0;
            res++;
        }
        return 0;
    }
    return ma;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]; a[i]--;
        if(i==0){
            if(a[i]!=0) res++;
            a[i]=0;
            continue;
        }
        g[a[i]].push_back(i);
    }
    dfs(0);
    cout<<res<<endl;
}
