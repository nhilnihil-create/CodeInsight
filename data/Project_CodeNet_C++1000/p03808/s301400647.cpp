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
long long mod = 998244353;
 
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
  long long n;
  cin >> n;
  long long arr[n];
  long long sum = 0;
  long long orig = n*(n+1)/2;
  for (int i=0; i<n; i++){
      cin >> arr[i];
      sum += arr[i];
  }
  if (sum%orig != 0){
      cout << "NO";
      return 0;
  }
  long long times = sum/orig;
  for (int i=0; i<n; i++){
      if (arr[i] < times || arr[i] > times*n){
          cout << "NO";
          return 0;
      }
  }
  long long diffs[n];
  long long diffsum = 0;
  for (int i=1; i<n; i++){
      diffs[i-1] = arr[i]-arr[i-1];
      diffsum += diffs[i-1];
  }
  diffs[n-1] = arr[0]-arr[n-1];
  diffsum += diffs[n-1];
  if (diffsum != 0){
      cout << "NO";
      return 0;
  }
  // x+y = times
  // x = times-y
  // x-(n-1)y = diff
  // -n*y = diff-times
  // y = (diff-times)/(-n)
  // all y's should add to times
  int ytimes = 0;
  for (int i=0; i<n; i++){
      long long diff = diffs[i];
      long long y = diff-times;
      if (y%n != 0){
          cout << "NO";
          return 0;
      }
      ytimes += y/(-n);
  }
  if (ytimes != times){
      cout << "NO";
  }else{
      cout << "YES";
  }
  return 0; 
}