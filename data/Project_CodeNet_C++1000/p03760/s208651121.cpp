#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  string S1, S2; cin >> S1 >> S2;
  rep(i,S2.size()){
    cout << S1[i] << S2[i];
 }
  if(S1.size() > S2.size()) cout << S1[S1.size()-1];
  cout << endl;
  
  return 0;
}