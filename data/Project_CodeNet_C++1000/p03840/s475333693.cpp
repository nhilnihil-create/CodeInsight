#include <bits/stdc++.h>
using namespace std;

int main() {
  long long ai, ao, at, aj, al, as, az;
  cin>>ai>>ao>>at>>aj>>al>>as>>az;
  long long ans = ao;
  int mod_ai = ai % 2;
  int mod_aj = aj % 2;
  int mod_al = al % 2;
  if (mod_ai + mod_aj + mod_al == 0) {
    ans += ai + aj + al;
  } else if (mod_ai + mod_aj + mod_al == 1) {
    ans += (ai / 2 + aj / 2 + al / 2) * 2;
  } else if (ai > 0 && aj > 0 && al > 0) {
    ans += 3 + ((ai - 1) / 2 + (aj - 1) / 2 + (al - 1) / 2) * 2;
  } else {
    ans += (ai / 2 + aj / 2 + al / 2) * 2;
  }
  cout<<ans<<endl;
}