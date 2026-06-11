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

const long long MOD = 1e9+7;

void solve()
{
  string a, b; cin >> a >> b;
  int asize = a.size(), bsize = b.size();
  if(asize > bsize) {
    cout << "GREATER" << endl;
    return ;
  }
  else if(asize < bsize) {
    cout << "LESS" << endl;
    return ;
  }
  int i = 0;
  while(i < asize){
    if(a[i]-'a' > b[i]-'a'){
      cout << "GREATER" << endl;
      return;
    } else if(a[i] - 'a' < b[i]-'a') {
      cout << "LESS" << endl;
      return;
    } else {
      i++;
    }
  }
  cout << "EQUAL" << endl;

}

int main()
{
  solve();
  return 0;
}