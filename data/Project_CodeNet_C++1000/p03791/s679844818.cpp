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
 

int main ()
{
  prep();
  int n;
  cin >> n;
  int arr[n];
  
  for (int i=0; i<n; i++){
      cin >> arr[i];
  }
  int below = 0;
  int cnt = 0;
  int nums[n] = {0};
  for (int i=0; i<n; i++){
      // spaces = arr[i]-1
      int divv = (arr[i]-1)/2+(arr[i]-1)%2;
      nums[i] = cnt;
      if (below == divv && (arr[i]-1)%2 == 1){
          below--;
          cnt++;
      }
      below++;
  }

  long long res = 1;
 
  int numcnt[n+1] = {0};
  for (int i=0; i<n; i++){
      numcnt[nums[i]]++;
      //cout << nums[i] << " ";
  }
  int cursum = 0;
  for (int i=0; i<n; i++){
      cursum += numcnt[i];
      res *= cursum-i;
      res %= mod;
  }
  cout << res;
  return 0; 
}