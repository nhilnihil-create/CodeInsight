#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int main(){
  int n; string s; cin >> n >> s;
  rep(bit, (1<<2)){
    vector<bool> sheep(n+1,0);
    sheep[0] = (bit & 1);
    sheep[1] = (bit & 10);
    for (int i = 1; i < n; i++) {
      if(sheep[i] == (s[i] == 'o')) sheep[i+1] = sheep[i-1];
      else sheep[i+1] = !sheep[i-1];
    }
    //整合性の確認
    if(sheep[n] == sheep[0] && ((s[0] == 'o')==sheep[0]) == (sheep[1]==sheep[n-1])){
      rep(i, n) std::cout << ((sheep[i]) ? 'S' : 'W');
      std::cout << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
}
