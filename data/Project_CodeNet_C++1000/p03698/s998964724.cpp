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
  map<char, int> mp;
  rep(i, (int)S.size()) mp[S[i]]++;
  for (auto itr : mp){
    if (itr.second>1) {
      cout << "no"<<endl;
      return 0;
    }
  }
  cout <<  "yes" << endl;
}
