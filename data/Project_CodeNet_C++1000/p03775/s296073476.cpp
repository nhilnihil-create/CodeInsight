#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

const int INF = 1e8;
typedef long long ll;
ll n;

int f(ll a, ll b){
    string s, t;
    s = to_string(a), t = to_string(b);
    return max(s.length(), t.length());
}

int main(){
    cin >> n;

    int ans = INF;
    
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            ans = min(ans, f(i, n/i));
        }
    }

    cout << ans << endl;
    return 0;
}