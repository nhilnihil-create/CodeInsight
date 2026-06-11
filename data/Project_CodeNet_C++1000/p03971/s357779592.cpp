#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
// #define sort(a) sort(all(a))
using P = pair<int, int>;
using ll = long long;
using ld = long double;
typedef vector<int> vi;
int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0,-1, 0 };
const ll MOD = 1000000007;
#define PI 3.14159265358979323846264338327950L


using Graph = vector<vector<int>>;

signed main() {
  int a,b,n;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  bool flag;
  int kcnt = 0; // 海外の学生の中での順位
  int ycnt = 0; // 予選通過人数
  for (int i = 0; i < s.size(); i++) {
    flag = false;
    if(s[i]=='b') kcnt++;
    if(s[i]=='a' && ycnt<a+b) {
      flag = true;
      ycnt++;
    } else if(s[i]=='b' && ycnt<a+b && kcnt<=b) {
      flag = true;
      ycnt++;
    }
    if(flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}