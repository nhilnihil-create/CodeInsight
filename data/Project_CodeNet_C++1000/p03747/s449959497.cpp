#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())

using namespace std;

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(){
  int64_t n,l,t;
  cin >> n >> l >> t;
  vector<pair<int, int>> xw(n);
  REP(i,n){
    cin >> xw.at(i).first >> xw.at(i).second;
  }
  int x = xw.at(0).first;
  int w = xw.at(0).second;
  int64_t r = 0; // 0地点が最終的にxの何になるか
  for (auto i:xw){
    if (i.first != x){
      if (i.second != w){
        if (w == 1){
          r += t*2/l;
          if ((t*2%l) > (i.first - x)){
            r++;
          }
        }else{
          r -= t*2/l;
          if ((t*2%l) >= (l - (i.first - x))){
            r--;
          }
        }
      }
    }
  }
  if (r<= 0){
    r = n + r % n;
  }else{
    r = r % n;
  }
  int key; // 0地点の最終地点
  if (w == 1){
    key = (x + t % l) % l;
  }else{
    key = x - t % l;
    if (key < 0){
      key = l + key;
    }
  }
  vector<int64_t> vec(n);
  REP(j,n){
    pair<int, int> i = xw.at(j);
    int64_t z;
    if (i.second == 1){
      z = (i.first + t % l) % l;
    }else{
      z = i.first - t % l;
      if (z < 0){
        z = l + z;
      }
    }
    vec.at(j) = z;
  }
  SORT(vec);
  int index; // 0地点のvec内の位置
  REP(i, n){
    if (vec.at(i) == key){
      index = i;
      break;
    }
  }
  REP(i, n){
    int last = (i + index - r)%n;
    if (last < 0){
      last = n + last;
    }
    cout << vec.at(last) << endl;
  }
  return 0;
}

