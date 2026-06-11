#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

  int n,x;
  cin >> n >> x;
  ll cnt = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  for (int i = 0; i < n - 1; i++) {
    if (a.at(i)+a.at(i+1) > x) {
      cnt += (a.at(i)+a.at(i+1))-x;
      //cout << cnt <<endl;
      a.at(i+1) = x-a.at(i);
      if (a.at(i+1) < 0) {
        int t = a.at(i+1);
        a.at(i+1) = 0;
        a.at(i) += t;
      }
    }
  }

  /*for (int i = 0; i < n; i++) {
    cout<<"\n" << a.at(i) << endl;
  }*/

  cout << cnt << endl;
}
