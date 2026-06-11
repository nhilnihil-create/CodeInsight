#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  deque<int> d;
  rep(i, n){
    int x;
    cin >> x;
    if(i % 2 == 0) d.push_back(x);
    else d.push_front(x);
  }
  if(n % 2) reverse(d.begin(), d.end());
  rep(i, n) {
    cout << d.at(i);
    if(i != n - 1) cout << " ";
    else cout << endl;
  }
  
  return 0;
}