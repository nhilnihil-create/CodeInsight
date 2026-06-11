#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  string s;
  cin >> s;
  
  vector<char> t(0);
  for (int i = 0; i < s.size(); i++){
    if (t.size() == 0)
      t.emplace_back(s[i]);
    else if (t[t.size()-1] == 'S' && s[i] == 'T'){
      t.pop_back();
    }
    else {
      t.emplace_back(s[i]);
    }
  }
 
  cout << t.size() << endl;

  return 0;
}
