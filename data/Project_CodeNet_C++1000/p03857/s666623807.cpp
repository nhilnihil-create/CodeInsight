#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


class UnionFind
{
public:
  UnionFind(int n)
  {
    parent=vector<int>(n,-1);
  }
  int root(int a)
  {
    if(parent[a]<0)return a;
    return parent[a]=root(parent[a]);
  }
  int size(int a)
  {
    return -parent[root(a)];
  }
  bool connect(int a,int b)
  {
    int A=root(a);
    int B=root(b);
    if(A==B)return false;
    if(size(A)>size(B))swap(A,B);
    parent[B]+=parent[A];
    parent[A]=B;
    return true;
  }
private:
  vector<int> parent;

};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,l;
  cin>>n>>k>>l;
  UnionFind uf1(n),uf2(n);
  rep(i,k)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    uf1.connect(a, b);
  }
  rep(i,l)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    uf2.connect(a, b);
  }
  unordered_map<ll,int>ma;
  vector<ll>mem(n);
  rep(i,n)
  {
    ma[mem[i]=((ll)uf1.root(i)<<20)+uf2.root(i)]++;
  }
  rep(i,n)
  {
    cout<<ma[mem[i]]<<" ";
  }
  cout<<flush;
  return 0;

}
