#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll N;
    bool check = true;
    cin >> N;
    ll cnt_4 = 0, cnt_2 = 0, other = 0;
    for (int i = 0; i < N; i++) {
      ll tmp = 0;
      cin >> tmp;
      if (tmp % 4 == 0) cnt_4++;
      else if(tmp%2==0){
        cnt_2++;
      }
      else{
        other++;
      }
    }
    if (cnt_2 == 0) {
      if (cnt_4 >= other - 1) check = false;
    } else {
      if (cnt_2 % 2 == 0) {
        if (cnt_4 >= other - 1) check = false;
      } else {
        if (cnt_4 >= other) check = false;
      }
    }
    if (check) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}