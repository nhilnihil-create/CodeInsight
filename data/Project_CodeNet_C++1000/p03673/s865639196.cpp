#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n;
  cin >> n;
  
  vector<int> l, r;
  //bool f = true; //true:左から読む（右末尾に追加）
  
  rep(i, n)
  {
    int a;
    cin >> a;
    
    if(i%2 == 0)
    {
      l.push_back(a);
    }
    else
    {
      r.push_back(a);
    }
  }
  
  if(n%2 == 1)
  {
    reverse(l.begin(), l.end());
    rep(i, l.size()) cout << ((i != 0)? " " : "") << l[i];
    rep(i, r.size()) cout << " " << r[i];
  }
  else
  {
    reverse(r.begin(), r.end());
    rep(i, r.size()) cout << ((i != 0)? " " : "") << r[i];
    rep(i, l.size()) cout << " " << l[i];
  }
  cout << endl;
  
  
  return 0;
}