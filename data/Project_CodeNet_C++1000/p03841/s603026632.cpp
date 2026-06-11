#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
int q[N * N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> f;
  int x;
  for(int i = 1; i <= n ; i ++ ){
    cin >> x;
    f.push_back(mp(x,i));
  }
  sort(f.begin(), f.end());
  int idx = 1;
  int cnt;
  for(int i = 1; i <= n * n; i ++ )
    q[i] = -1;
  for(auto p : f){
    cnt = p.se - 1;
    while(cnt > 0){
      if(q[idx] == -1){
        q[idx] = p.se;
        idx++;
        --cnt;
      }
      else{
        idx++;
      }
    }
    if(idx > p.fi){
      cout << "No\n";
      return 0;
    }
    else if(idx == p.fi){
      q[idx] = p.se;
      idx ++ ;
    }
    else{
      q[p.fi] = p.se;
    }
  }
  idx = n * n;
  reverse(f.begin(), f.end());
  for(auto p : f){
    cnt = n - p.se;
    while(cnt > 0){
      if(q[idx] == -1){
        q[idx] = p.se;
        idx--;
        --cnt;
      }
      else{
        idx--;
      }
    }
    if(idx < p.fi){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  for(int i = 1; i <= n * n ; i ++ ){
    cout << q[i] << " ";
  }
  cout << "\n";
  return 0;
}