#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define P pair<int,int>
#define PP pair<P,int>
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()

struct UF {
  vector<int> data;
  UF(int size) : data(size, -1) { }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};


int main(){
    int n,k,l;
    cin>>n>>k>>l;
    UF p(n);
    UF q(n);
    REP(i,k){
        int a,b;
        cin>>a>>b;
        a--;b--;
        p.unite(a,b);
    }
    REP(i,l){
        int a,b;
        cin>>a>>b;
        a--;b--;
        q.unite(a,b);
    }
    map<P,int> ma;
    REP(i,n){
        ma[P(p.root(i),q.root(i))]++;
    }
    REP(i,n){
        if(i)cout<<" ";cout<<ma[P(p.root(i),q.root(i))];
    }cout<<endl;
    return 0;
}