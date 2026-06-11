#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  set<int> t;
  multiset<int> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
    t.insert(a);
  }
  int sum = s.size() - t.size() + 1;
  sum /= 2;
  sum *= 2;//食べる数

  cout << n-sum << endl;

}
