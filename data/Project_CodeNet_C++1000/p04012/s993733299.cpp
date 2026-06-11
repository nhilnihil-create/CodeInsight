#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  string w;
  cin >> w;
  
  int alph[26] = {};
  for (int i = 0; i < w.size(); i++){
    alph[w[i]-'a']++;
  }

  int ok = 1;
  for (int i = 0; i < 26; i++){
    if (alph[i] % 2 == 1)
      ok = 0;
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    

  return 0;
}
