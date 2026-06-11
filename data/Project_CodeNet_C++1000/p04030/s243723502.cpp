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

char ans[15];

int main(){
  string S; cin >> S;
  int now = 0;

  for (int i = 0; i < S.length(); i++){
    if (S[i] == 'B'){
      if (now > 0) now--;
    }else{
      ans[now] = S[i];
      now++;
    }
  }

  for (int i = 0; i < now; i++) cout << ans[i];
  cout << endl;

  return 0;
}
