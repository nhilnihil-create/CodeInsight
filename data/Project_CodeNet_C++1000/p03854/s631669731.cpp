#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;
string s;

string hoge(string s, int i, int j){
  string t = "";
  for (int k = 0; k < j; k++){
    t += s[i+k];
  }
  return t;
}

bool ok(int j){
  if (j == 0)
    return true;

  if (j >= 5 && hoge(s, j-5, 5) == "dream"){
    return ok(j-5);
  }
  if (j >= 7 && hoge(s, j-7, 7) == "dreamer"){
    return ok(j-7);
  }
  if (j >= 5 && hoge(s, j-5, 5) == "erase"){
    return ok(j-5);
  }
  if (j >= 6 && hoge(s, j-6, 6) == "eraser"){
    return ok(j-6);
  }

  return false;
}

int main(void){
  cin >> s;
  
  
  if (ok(s.size()))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
