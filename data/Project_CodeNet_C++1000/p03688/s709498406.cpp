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

int main(){
  prep();
  int n;
  cin >> n;
  int arr[n];
  int maxx = 0;
  int minn = 1000000000;
  for (int i=0; i<n; i++){
      cin >> arr[i];
      maxx = max(maxx, arr[i]);
      minn = min(arr[i], minn);
  }
  if (maxx-minn > 1){
      cout << "No";
      return 0;
  }
  if (maxx == minn){
      if (n/2 < maxx && !(maxx == n-1)){
          cout << "No";
      }else{
          cout << "Yes";
      }
      return 0;
  }
  int distinct = 0;
  for (int i=0; i<n; i++){
      if (arr[i] == minn){
          distinct++;
      }
  }
  if (n-distinct == 1){
      cout << "No";
      return 0;
  }
  int more = (n-distinct)/2;
  if (more+distinct >= maxx && distinct+1 <= maxx){
      cout << "Yes";
  }else{
      cout << "No";
  }
  return 0; 
}