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

int N; ll A[int(1e5+5)];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  ll cnt1 = 0, sum1 = 0;
  for (int i = 0; i < N; i++){
    sum1 += A[i];
    if (i % 2 == 0 && sum1 <= 0){
      cnt1 += abs(sum1) + 1;
      sum1 = 1;
    }else if (i % 2 != 0 && sum1 >= 0){
      cnt1 += sum1 + 1;
      sum1 = -1;
    }
  }

  ll cnt2 = 0, sum2 = 0;
  for (int i = 0; i < N; i++){
    sum2 += A[i];
    if (i % 2 == 0 && sum2 >= 0){
      cnt2 += sum2 + 1;
      sum2 = -1;
    }else if (i % 2 != 0 && sum2 <= 0){
      cnt2 += abs(sum2) + 1;
      sum2 = 1;
    }
  }

  cout << min(cnt1, cnt2) << endl;


  return 0;
}
