#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

std::vector<std::vector<long long> > comb(int n, int r) {
  std::vector<std::vector<long long> > v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}


int main(){
    long long n, p;
    cin >> n >> p;

    long long even = 0, odd = 0;
    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        if(a % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    long long ans = 0;
    if(p == 0){

        long long i = 0;
        while(i <= odd){
            vector<vector<long long> > v;
            v = comb(odd, i);
            ans = ans + v[odd][i];
            i += 2;
        }
        ans = ans*pow(2, even);
    }
    else{
        long long i = 1;
        while(i <= odd){
            vector<vector<long long> > v;
            v = comb(odd, i);
            ans = ans + v[odd][i];
            i += 2;
        }
        ans = ans*pow(2, even);
    }

    cout << ans << endl;
}