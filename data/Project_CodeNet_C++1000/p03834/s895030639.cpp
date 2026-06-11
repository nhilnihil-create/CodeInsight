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
  rep(i,19){
    if(i == 5 || i == 13) cout << " ";
    else cout << S[i];
  }
  cout << endl;
  return 0;
  
}