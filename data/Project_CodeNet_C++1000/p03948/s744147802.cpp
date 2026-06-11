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
  int n, k;
  cin >> n >> k;
  if (n == 1){
      cout << 0;
      return 0;
  }
  int arr[n];
  for (int i=0; i<n; i++){
      cin >> arr[i];
  }
  int maxest[n];
  int maxx = 0;
  for (int i=n-1; i>=0; i--){
      maxx = max(maxx, arr[i]);
      maxest[i] = maxx;
  }
  int biggest = 0;
  for (int i=0; i<n-1; i++){
      biggest = max(biggest, maxest[i+1]-arr[i]);
  }
  int cnt =0;
  for (int i=0; i<n-1; i++){
      int now = maxest[i+1]-arr[i];
      if (now == biggest){
          cnt++;
      }
  }
  cout << cnt;
  return 0; 
}
