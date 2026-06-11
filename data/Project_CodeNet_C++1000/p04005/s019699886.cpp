#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  ll A = 0, B = 0, C = 0;
  vector<ll>z(3);
  cin >> A >> B >> C;
  z[0] = A; z[1] = B; z[2] = C;
  if(A % 2 == 0 || B % 2 == 0 || C % 2 == 0){
    cout << "0";
    return 0;
  }
  sort(z.begin(), z.end()); //小さい順
  cout << z[0] * z[1];
}
  