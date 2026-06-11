#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  vector<char> v;
  char c;
  while(cin >> c){
    if(c == '0') v.push_back('0');
    else if(c == '1') v.push_back('1');
    else{
      if(v.empty()) continue;
      else v.pop_back();
    }
  }
  
  for(char x : v) cout << x;
  cout << endl;
    
  return 0;
}
