#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  deque<ll> mt;//バスを待ってる人が乗れる最遅の便
  int cnt = 0;
  rep(i,n) cin >> t[i];
  sort(t.begin(),t.end());
  rep(i,n-1) {
    int people=0;//乗客
    mt.push_back(t[i]+k);
    while(mt.size()>0&&mt.front()<t[i+1]) {
      people++;
      mt.pop_front();
    }
    while(mt.size()>0&&people%c!=0) {
      people++;
      mt.pop_front();
    }
    cnt+=(people+c-1)/c;
  }
  cnt+=(mt.size()+c)/c;

  cout << cnt << endl;
}
