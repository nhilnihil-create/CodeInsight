#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}
 
 
int nextInt() { int x; scanf("%d", &x); return x;}
 
const int MAX_N = 100000;
vector<int> g[MAX_N];
 
int f(int v, int prev) {
  int x = 0;
  for (int u : g[v]) if (u != prev) {
    x ^= f(u, v);
  }
  x += 1;
  // cout << v << " " << x << endl;
  return x;
}
 
int main2() {
  int N = nextInt();
  REP(i, N) g[i].clear();
  REP(_, N-1) {
    int x = nextInt() - 1;
    int y = nextInt() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int nim = f(0, -1) - 1;
  if (nim == 0) cout << "Bob" << endl; 
  else cout << "Alice" << endl;
  return 0;
}
 
int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}