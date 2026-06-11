#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  int cnt1 = 0;
  int cnt2 = 0;
  rep(i,s.size()){
    if(s[i] == 'a'){
      if(cnt1<a+b){
        cnt1++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    if(s[i] == 'b'){
      if(cnt1<a+b&&cnt2<b){
        cnt1++;
        cnt2++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    if(s[i] == 'c') cout << "No" << endl;
  }
  return 0;
}