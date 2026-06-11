#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  vector<ll> num(13);
  num[4] = 1;
  num[6] = 1;
  num[9] = 1;
  num[11] = 1;
  num[2] = 2;
  int a, b;
  cin >> a >> b;
  if(num[a] == num[b]) cout << "Yes";
  else cout << "No";
}
