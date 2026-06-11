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


int main(int argc, char const *argv[]) {
    int n,m;cin>>n>>m;
    vector<bool> se(n);
    deque<int> res(0);
    vector<set<int>> G(n,set<int>());
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        G[u].insert(v);
        G[v].insert(u);
        if(i==0){
            res.push_back(u);
            res.push_front(v);
            se[u] = 1;
            se[v] = 1;
        }
    }
    while(true){
        int v = res.back();
        for(auto itr=G[v].begin();itr!=G[v].end();itr++){
            if(!se[*itr]){
                res.push_back(*itr);
                se[*itr] = 1;
                break;
            }
        }
        if(v==res.back())break;
    }
    while(true){
        int v = res.front();
        for(auto itr=G[v].begin();itr!=G[v].end();itr++){
            if(!se[*itr]){
                res.push_front(*itr);
                se[*itr] = 1;
                break;
            }
        }
        if(v==res.front())break;
    }
    cout<<res.size()<<endl;
    for(auto itr = res.begin();itr != res.end();itr++)cout<<*itr+1<<endl;
    return 0;
}