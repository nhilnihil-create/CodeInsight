#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;

long long n,k,res;
vector<int> a,dp;
vector<vector<int>> G;

int dfs(int i){
    int w = 0;
    for(int u:G[i])w=max(w,dfs(u));
    if(w+1>=k && a[i]!=0){
        res++;
        // cout<<i<<endl;
        return 0;
    }
    return w+1;
}

int main(int argc, char const *argv[]) {
    cin>>n>>k;
    res = 0;
    a = vector<int>(n);
    G = vector<vector<int>>(n);
    for(int i=0;i<n;++i)cin>>a[i];
    if(a[0]!=1){
        res++;
    }
    a[0] = 0;
    for(int i=1;i<n;++i){
        a[i]--;
        G[a[i]].push_back(i);
    }
    dfs(0);
    cout<<res<<endl;
    return 0;
}