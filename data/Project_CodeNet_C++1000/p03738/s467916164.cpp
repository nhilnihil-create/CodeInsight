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
  string A, B; cin >> A >> B;
  if(A == B) { cout << "EQUAL" << endl; return 0;}
  
  if(A.size() > B.size()){ cout << "GREATER" << endl; return 0;}
  else if (A.size() < B.size()){ cout << "LESS" << endl; return 0;}
  
  rep(i,A.size()){
    if(A[i]<B[i]){ cout << "LESS" << endl; return 0;}
    else if(A[i]>B[i]){ cout << "GREATER" << endl; return 0;}
  }
  return 0;
}