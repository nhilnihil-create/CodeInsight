#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a[3];
  rep(i,3) cin >> a[i];

  int five = 0;
  int seven = 0;
  rep(i,3){
    if (a[i] == 5) five ++;
    if (a[i] == 7) seven ++;
  }

  if (five == 2 && seven == 1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
