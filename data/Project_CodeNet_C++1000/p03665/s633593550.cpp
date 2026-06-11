#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long comb(int n, int r) {
  vector<vector<long long> > v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v[n][r];
}

int main(){
    long long n, p;
    cin >> n >> p;

    vector<long long> a(n);
    long long cnt_odd = 0;
    long long cnt_even = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) cnt_even++;
        else cnt_odd++;
    }

    long long ans = 1;
    for(long long i = 0; i < cnt_even; i++) ans *= 2;
    long long cnt = 0;
    if(p == 0){
        for(long long i = 0; i <= cnt_odd; i += 2) cnt += comb(cnt_odd, i);
    }
    else{
        for(long long i = 1; i <= cnt_odd; i += 2) cnt += comb(cnt_odd, i);
    }
    ans *= cnt;

    cout << ans << endl;
    return 0;
}