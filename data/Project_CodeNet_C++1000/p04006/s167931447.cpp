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
 
// 32 mil = ~1 sec 
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

int main ()
{
  prep();
  long long n, x;
  cin >> n >> x;
  int arr[n];
  long long tot = 0;
  for (int i=0; i<n; i++){
      cin >> arr[i];
      tot += arr[i];
  }
  int minels[n];
  for (int i=0; i<n; i++){
      minels[i] = 2000000000;
  }
  long long minnest = 1000000000000000000LL;
  for (int i=0; i<=n; i++){
      // search rotations
      long long cost = i*x+tot;
      for (int j=0; j<n; j++){
          minels[j] = min(minels[j], arr[(j-i+n)%n]);
          cost += min(0, minels[j]-arr[j]);
      }
      minnest = min(minnest, cost);
  }
  cout << minnest;
  return 0; 
}
