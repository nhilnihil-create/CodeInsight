#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main (){
  int n, m;
  cin >> n >> m;
  vector<pair<bool, int>> v(n+10, make_pair(false,1));
  bool f = true;
  v[1].first = true;

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    v[x].second--;
    v[y].second++;
    if(v[x].first){v[y].first = true;}
    if(v[x].second == 0){v[x].first = false;}
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(v[i].first){cnt++;}
  }
  cout << cnt << endl;
}