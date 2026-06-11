#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  string s;
  cin >> s;

  ll g = 0, p = 0;

  int n = s.size();

  for (int i = 0; i < n; i++)
    if(s[i] == 'g'){
      g++;
    }
    else{
      p++;
    }

  ll ans = (g-p)/2;

  cout << ans << endl;
}
