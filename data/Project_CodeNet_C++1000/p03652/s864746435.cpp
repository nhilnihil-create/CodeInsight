#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector < queue < int > > q(n + 1);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int a;
      cin >> a;
      q[i].push(a);
    }
  }

  vector < bool > used(m + 1, false);
  int mi = INT_MAX;
  for(int i = 1; i <= m; i++){
    vector < int > cnt(m + 1, 0);
    for(int j = 1; j <= n; j++){
      while(used[q[j].front()]) q[j].pop();
      cnt[q[j].front()]++;
    }
    int mx = INT_MIN, color = 0;
    for(int j = 1; j <= m; j++){
      if(!used[j] && cnt[j] > mx){
        mx = cnt[j];
        color = j;
      }
    }

    mi = min(mi, mx);
    used[color] = true;
  }

  cout << mi << '\n';
}
