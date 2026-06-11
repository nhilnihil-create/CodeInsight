#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  int ans = 0, over = 0;
  int base = 400;
  int rate[8];
  rep(i, 8) {
    rate[i] = 0;  
  }
  rep(i, n){
    int check = -1;
    if(a[i] >= 1 && a[i] < base) {
      rate[0]++; check = 0;
    }else if(a[i] >= base && a[i] < base * 2) {
      rate[1]++; check = 1;
    }else if(a[i] >= base * 2 && a[i] < base * 3) {
      rate[2]++; check = 2;
    }else if(a[i] >= base * 3 && a[i] < base * 4) {
      rate[3]++; check = 3;
    }else if(a[i] >= base * 4 && a[i] < base * 5) {
      rate[4]++; check = 4;
    }else if(a[i] >= base * 5 && a[i] < base * 6) {
      rate[5]++; check = 5;
    }else if(a[i] >= base * 6 && a[i] < base * 7) {
      rate[6]++; check = 6;
    }else if(a[i] >= base * 7 && a[i] < base * 8) {
      rate[7]++; check = 7;
    }else {
      over++;
    }
    if(check != -1 && rate[check] == 1) ans++;
  }
  if (over > 0 && ans == 0) {
    ans ++;
    over --;
  }
  cout << ans << " " << ans+over << endl;
  
}