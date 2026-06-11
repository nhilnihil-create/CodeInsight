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
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (a > b){
      swap(a, b);
  }
  b -= a;
  a = 0;
  if (d*(n-1) < b){
      cout << "NO";
      return 0;
  }
  
  bool found = false;
  for (int i=0; i<=n-2 && !found; i++){
      long long cursum = -c*i+c*(n-1-i);
      if (cursum > b){
          long long maxdecr = c*(n-1-i)-d*i;
          if (b >= maxdecr){
              found = true;
          }
      }else if (cursum < b){
          long long maxincr= -c*i+d*(n-1-i);
          if (b <= maxincr){
              found = true;
          }
      }else{
          found = true;
      }
  }
  if (found){
      cout << "YES";
  }else{
      cout << "NO";
  }
  return 0; 
}