#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int h, w;
  cin >> w >> h;
  vector < pair < int, int > > v;
  for(int i = 0; i < w; i++){
    int p;
    cin >> p;
    v.push_back({p, 0});
  }
  for(int i = 0; i < h; i++){
    int q;
    cin >> q;
    v.push_back({q, 1});
  }

  sort(v.begin(), v.end());
  ll x = h + 1, y = w + 1;
  ll total_wt = 0;
  for(int i = 0; i < h + w; i++){
    if(v[i].second == 0){
      total_wt += x * v[i].first;
      y--;
    }else{
      total_wt += y * v[i].first;
      x--;
    }
  }

  cout << total_wt << '\n';
}
