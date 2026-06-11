#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FOREACH(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))

struct PersistentUnionFind {
 
    int global_time;
    vector < vector < int > > rank;
    vector < vector < int > > time;
    vector < vector < int > > parent;
 
    PersistentUnionFind(int n) : rank(n), time(n), parent(n) {
        for (int i = 0; i < n; i++) {
            rank[i].push_back(1);
            time[i].push_back(0);
            parent[i].push_back(i);
        }
        global_time = 0;
    }
 
    bool unite(int x, int y) {
        global_time++;
        x = root(x, global_time); 
        y = root(y, global_time);
        if (x != y) {
            if (rank[y] > rank[x]) swap(x, y);
            int r = rank[x].back() + rank[y].back();
            rank[x].push_back(r);
            rank[y].push_back(r);
            time[x].push_back(global_time);
            time[y].push_back(global_time);
            parent[x].push_back(x);
            parent[y].push_back(x);
        }
        return x != y;
    }
 
    bool same(int x, int y, int t) {
        return root(x, t) == root(y, t);
    }
 
    int root(int x, int t) {
        if (parent[x].back() == x) return x;
        if (time[x].back() > t) return x;
        return root(parent[x].back(), t);
    }
 
    int size(int x, int t) {
        int v = root(x, t);
        int l = 0, r = (int) time[v].size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (time[v][m] <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        return rank[v][l];
    }
 
    bool same(int x, int y) { return same(x, y, global_time); }
    int  root(int x) { return root(x, global_time); }
    int  size(int x) { return size(x, global_time); }
 
}; 

int main(){
 
    int N,K,L; cin>>N>>K>>L;
    PersistentUnionFind inst1(200010);
    PersistentUnionFind inst2(200010);
    REP(i,K){
        int p,q; cin>>p>>q;
        inst1.unite(p,q);
    }
    REP(i,L){
        int r,s; cin>>r>>s;
        inst2.unite(r,s);
    }
    
    map<int,vector<int> > same_g;
    for(int i=1;i<=N;i++){
        same_g[inst1.root(i)].push_back(i);
    }
    
    int ans[200010]={};
    FOREACH(i,same_g){
        vector<int> t=i->second;
        map<int,int> root;
        REP(j,t.size()){
            int r=inst2.root(t[j]);
            if(root.find(r)==root.end())root[r]=1;
            else root[r]++;
        }
        REP(j,t.size())ans[t[j]]=root[inst2.root(t[j])];
    }
    
    for(int i=1;i<N;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[N]<<endl;
    
    return 0;
}