#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cout << setprecision(10);
  ll N,K; cin >> N >> K;

  ll gcd_val;
  ll max_val = 0;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    max_val = max(max_val, tmp);
    if(tmp == K){
      cout << "POSSIBLE" << endl;
      return 0;
    }
    if(i == 0){
      gcd_val = tmp;
    } else { 
      gcd_val = gcd(gcd_val, tmp);
    }
  }

  if(K > max_val){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  if(K % gcd_val == 0){
    cout << "POSSIBLE" << endl;
    return 0;
  } else { 
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
}
