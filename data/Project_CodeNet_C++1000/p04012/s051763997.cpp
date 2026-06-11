#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  int app[27] = {0};
  int n = s.size();
  rep(i,n){
    app[s[i] - 'a']++;
  }
  
  rep(i,27){
    if(app[i] % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
}