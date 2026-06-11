#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool PN(T x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

void solve()
{
  long long x; cin >> x;
  if(PN(x)) {
    int order = 0;
    while(x){
      x/=10;
      order++;
    }
    cout << order << endl;
    return;
  } else {
    int target = 1;
    int target_order = 0;
    for(int i = 2; i <= sqrt(x); ++i){
      if(x % i == 0) target = i;
    }
    int another = x/target;
    int another_order=0;
    while(another){
      another/=10;
      another_order++;
    }
    while(target){
      target/=10;
      target_order++;
    }
    int ans = max(target_order, another_order);
    cout << ans << endl;
  }


}

int main()
{
  solve();
  return 0;
}