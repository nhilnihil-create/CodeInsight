#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
ll MOD=1000000007;

int main(){
  int n; cin>>n;
  vector<int>A(n), B(n);
  rep(i,n) cin>>A[i]>>B[i];
  int ma = -1;
  int num = -1;
  rep (i,n){
    if (ma<A[i]){
      ma = A[i];
      num = i;
    }
  }
  cout << A[num]+B[num] << endl;
}