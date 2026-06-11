#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1000000000000
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int p[500000];
int r[500000];

void init(int n){
  REP(i, n){
    p[i] = i;
    r[i] = 0;
  }
}

int find(int n) {return (p[n] == n ? n : p[n] = find(p[n]));}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(r[x] < r[y]) p[x] = y;
  else{
    p[y] = x;
    if(r[x] == r[y]) r[x]++;
  }
}

bool same(int x, int y){
  return (find(x) == find(y));
}

int main(){
  int n, k, l;
  cin >> n >> k >> l;
  init(2*n);
  REP(i, k){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    unite(x, y);
  }
  REP(i, l){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    unite(x+n, y+n);
  }
  P d[n];
  map<P, int> m;
  REP(i, n){
    d[i] = {find(i), find(i+n)};
    m[d[i]]++;
  }
  REP(i, n){
    cout << m[d[i]];
    if(i == n-1) cout << endl;
    else cout << " ";
  }
  return 0;
}