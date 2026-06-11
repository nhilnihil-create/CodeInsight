#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
int n, x, y;
pair<int, int> ratios[40];
int costs[40];
bool memoo[40][500][500];
int memo[40][500][500];
int func(int ind, int a, int b){
    if (ind >= n){
        int gcdd = __gcd(a, b);
        if (gcdd == 0){
            return 1000000000;
        }
        if (a/gcdd == x && y ==  b/gcdd){
            return 0;
        }
        return 1000000000;
    }
    if (memoo[ind][a][b]){
        return memo[ind][a][b];
    }
    int res = 0;
    // add it
    int newa = a+ratios[ind].first;
    int newb = b+ratios[ind].second;
    
    res = costs[ind]+func(ind+1, newa, newb);
    // don't
    res = min(res, func(ind+1, a, b));
    memoo[ind][a][b] = true;
    memo[ind][a][b] = res;
    return res;
}
int main(){
  prep();
  cin >> n >> x >> y;
  for (int i=0; i<n; i++){
      int a, b, c;
      cin >> a>> b >> c;
      ratios[i] = {a, b};
      costs[i] = c;
  }
  int res = func(0, 0, 0);
  if (res >= 1000000000){
      cout << -1;
  }else{
      cout << res;
  }
  return 0; 
}