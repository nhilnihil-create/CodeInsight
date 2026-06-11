#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
  }*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1LL<<60;

signed main() {
  int n;
  cin >> n;

  vi a(3*n);
  rep(i, 0, 3*n) cin >> a[i];

  vi L(n+1), R(n+1);
  int suml = 0, sumr = 0;
  priority_queue<int, vi, greater<int>> quel;
  priority_queue<int> quer;
  rep(i, 0, n){
    suml += a[i];
    quel.push(a[i]);
    sumr += a[3*n-1-i];
    quer.push(a[3*n-1-i]);
  }

  L[0] = suml;
  R[n] = sumr;
  rep(i, 0, n){
    suml += a[i+n];
    quel.push(a[i+n]);
    suml -= quel.top();
    quel.pop();
    L[i+1] = suml;

    sumr += a[2*n-1-i];
    quer.push(a[2*n-1-i]);
    sumr -= quer.top();
    quer.pop();
    R[n-1-i] = sumr;
  }

//  rep(i, 0, n+1){
//    cout << L[i] << " ";
//  }
//  cout << endl;
//
//  rep(i, 0, n+1){
//    cout << R[i] << " ";
//  }
//  cout << endl;

  int ans = -1e15;
  rep(i, 0, n+1){
    chmax(ans, L[i]-R[i]);
  }

  cout << ans << endl;

  return 0;
}

