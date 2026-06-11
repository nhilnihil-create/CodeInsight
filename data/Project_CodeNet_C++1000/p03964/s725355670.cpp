#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

/*void find(int T[], int A[], ll TT[], ll AA[], int i) {
  int j = 2;
  while(1) {
    if (T[i] < TT[i-1] || A[i] < AA[i-1]) {
      T[i] *= j; A[i] *= j++;
    }
  }
  TT[i] = T[i]; AA[i] = A[i];
}*/
int main(void) {
  int n; cin >> n;
  int T[n], A[n];
  rep(i,n) {cin >> T[i] >> A[i];}
  ll TT[n],AA[n]; //実際の数値
  TT[0] = T[0]; AA[0] = A[0];

  rep2(i,1,n) {
    ll j, k;
    /*
        int j = 1;
      while(1) {
        if (T[i] * j < TT[i-1] || A[i] * j < AA[i-1]) {
          j++;
        } else {
          break;
        }
      }
      TT[i] = T[i]*j; AA[i] = A[i]*j;
      */
      //cout << TT[i] << " " << AA[i] << endl;
      if(TT[i-1] % T[i] == 0) j = TT[i-1] / T[i];
      else j = TT[i-1] / T[i] + 1;
      if(AA[i-1] % A[i] == 0) k = AA[i-1] / A[i];
      else k = AA[i-1] / A[i] + 1;
      TT[i] = T[i] * max(j, k);
      AA[i] = A[i] * max(j, k);
  }
  cout << TT[n-1]+AA[n-1] << endl;

}