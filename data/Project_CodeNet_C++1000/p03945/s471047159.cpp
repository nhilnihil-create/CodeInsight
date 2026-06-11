#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  string S; cin >> S;
  int count = 0;
  char crntC = S[0];
  rep(i, (int)S.size()){
    if(S[i] == crntC) continue;
    else {crntC = S[i]; count++;}
  }
  
  cout << count << endl;
  return 0;
}