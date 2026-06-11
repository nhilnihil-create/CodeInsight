#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
  int N, A, B; cin >> N >> A >> B;
  string S; cin >> S;

  int a = 0, b = 0;
  for (int i = 0; i < N; i++){
    if (S[i] == 'c'){
      No();
    }else if (S[i] == 'a'){
      if (a + b < A + B){
        Yes(); a++;
      }else{
        No();
      }
    }else{
      if (a + b < A + B && b < B){
        Yes(); b++;
      }else{
        No();
      }
    }
  }

  return 0;
}
