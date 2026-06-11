#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
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

    long long a[n];
    long long cnt_odd = 0, cnt_even = 0;

    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) cnt_even++;
        else cnt_odd++;
    }

    long long ans;
    if(p == 0){
        long long sum = 0;
        for(long long i = 0; i <= cnt_odd; i++){
            if(i % 2 == 0){
                sum += comb(cnt_odd, i);
            }
        }
        ans = pow(2, cnt_even) * sum;
    }
    else{
        long long sum = 0;
        for(long long i = 0; i <= cnt_odd; i++){
            if(i % 2 != 0){
                sum += comb(cnt_odd, i);
            }
        }
        ans = pow(2, cnt_even) * sum;
    }

    cout << ans << endl;
    return 0;
}