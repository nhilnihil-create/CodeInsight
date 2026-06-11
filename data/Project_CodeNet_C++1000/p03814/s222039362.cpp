#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  string s;
  cin >> s;
  
  ll a, z;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == 'A'){
      a = i;
      break;
    }
  }
  for (int i = 0; i < s.size(); i++){
    if (s[i] == 'Z'){
      z = i;
    }
  }

  cout << z - a + 1 << endl;

  return 0;
}
