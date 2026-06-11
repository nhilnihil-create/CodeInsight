#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, n) {
    int num;
    cin >> num;
    t.at(i) = num;
  }
  sort(t.begin(), t.end());
  int passenger = 0;
  int now_time = 0;
  int bus = 0;
  int first_pass_timelimit = 0;
  int first_pass_time = 0;
  rep(i, n) {
    passenger++;
    now_time = t.at(i);
    if (passenger == 1) {
      first_pass_time = t.at(i);
    }
    if (passenger > 1) {
      first_pass_timelimit = t.at(i) - first_pass_time;
    }
    //timelimit = t.at(i) - now_time_before;
    if (passenger >= c) {
      if (first_pass_timelimit <= k) {
        bus++;
        passenger = 0;
        first_pass_time = 0;
        first_pass_timelimit = 0;
        //cout << 123 << endl;
      }
    }
    if (first_pass_timelimit > k) {
      bus++;
      passenger = 1;
      first_pass_time = t.at(i);
      first_pass_timelimit = t.at(i) - first_pass_time;
      //cout << 456 << endl;
    }
  }
  if (passenger) {
    bus++;
    //cout << 789 << endl;
  }
  cout << bus << endl;
}
      
