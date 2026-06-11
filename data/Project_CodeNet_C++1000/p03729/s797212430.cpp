#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string a, b, c;
  cin >> a >> b >> c;

  if (a.at(a.size() - 1) == b.at(0) && b.at(b.size() - 1) == c.at(0)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
