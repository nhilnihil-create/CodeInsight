#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll zer = 0;


int main(){
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  ll z = 0, o = 0;
  rep(i, n){
    cin >> a[i];
    a[i] %= 2;
    if(a[i] % 2 == 0)z++;
    else o++;
  }
  if(p == 1 && o == 0){
    cout << 0 << endl;
    return 0;
  }
  ll res = 1;
  while(z > 0){
    res *= 2;
    z--;
  }
  o--;
  while(o > 0){
    res *= 2;
    o--;
  }
  cout << res << endl;
}


