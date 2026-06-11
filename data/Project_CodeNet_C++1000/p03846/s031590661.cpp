#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int N;
  cin >> N;
  vector<int> V(510000,0);
  rep(i,N){
    int A;
    cin >> A;
    V[A]++;
  }
  
  int sum = 0;
  
  bool x = true;

  if(N%2==1){
    if(V[0]!=1) x = false;
    
    for(int i = 1;i<=N/2; i++){
      if(V[2*i]!= 2) x = false;
    }
  }
  else{
    for(int i = 0;i<= N/2-1;i++){
      if(V[2*i+1]!=2) x = false;
    }
  }
  
  long long ans = 1;
  if(x){
    rep(i, N/2){
      ans *=2;
      ans %= 1000000007;
    }
     cout << ans << endl;
  }
  else{
    cout << 0 << endl;
  } 
}
      
       





      
       





