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
  int N, A, B; cin >> N >> A >> B;
  string S; cin >> S;
  int counta = A+B;
  int countb = B;
  rep(i,S.size()){
    if(S[i]=='c' || counta == 0) cout << "No" << endl;
    else if(S[i]=='a') {cout << "Yes" << endl; counta--;}
    else if(S[i]=='b' && countb != 0){cout << "Yes" << endl;counta--; countb--;}
    else cout << "No" << endl;
  }
  return 0;
}