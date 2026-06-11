#pragma GCC optimize ("O3")
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
#include <limits>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FOREACH(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
 
template <class T> struct FenwickTree {
 
   vector<T> node;
   FenwickTree (int n) : node(n,0) {}
 
   void add(int idx, T val) {
      for (int i = idx; i < node.size(); i |= i + 1) {
         node[i] += val;
      }
   }
 
   T sum(int idx) {
      T ret = 0;
      for (int i = idx - 1; i >= 0; i = (i & (i + 1)) - 1) {
         ret += node[i];
      }
      return ret;
   }
 
};
 
int N,M;
vector< pair<int,int> > add;
vector<int> l,r;
FenwickTree<int> inst(100010);
 
int main() {
 
  cin >> N >> M;
  l.resize(N);
  r.resize(N);
 
  REP(i,N) {
    int lt,rt; cin >> lt >> rt;
    l[i] = lt;
    r[i] = rt;
    add.push_back(make_pair(rt - lt + 1, i));
  }
  
  sort(add.begin(),add.end());
 
  int j = 0;
  for(int i=1; i<=M; i++) {
    while(j < add.size()) {
      if(add[j].first >= i) break;
      int idx = add[j].second;
      inst.add(l[idx],1);
      inst.add(r[idx]+1,-1);
      j++;
    }
 
    int ans = N - j;
    for(int k=i; k<=M; k+=i) ans += inst.sum(k+1);
    cout << ans << endl;
  }
 
  return 0;
}