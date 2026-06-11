#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  vector<bool> vec(26, false);
  rep(i, n){
    vec[s[i]-'a'] = true;
  }
  int smallest = 10000;
  rep(i, 26){
    if(!vec[i]) continue;
    string sc = s;
    for(int j=0; j<=n/2; j++){
      bool allSame = true;
      rep(k, n-j){
        if(sc[k] != 'a'+i) allSame = false; 
      }
      if(allSame){
        smallest = min(smallest, j);
        break;
      }
      rep(k, n-j-1){
        if(sc[k] == 'a'+i || sc[k+1] == 'a'+i) sc[k] = 'a'+i;
      }
    }
  }
  cout << smallest << endl;
  return 0;
}