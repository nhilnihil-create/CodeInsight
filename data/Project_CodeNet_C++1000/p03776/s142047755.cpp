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
map<long long, int> freqs;
map<long long, int> allfreqs;
long long choose(long long n, long long k){
   if (k == 0) return 1;
   return (n * choose(n - 1, k - 1)) / k;
}
int main ()
{
  prep();

  int n, a, b;
  cin >> n >> a >>b;
  long long arr[n];
  for (int i=0; i<n; i++){
      cin >> arr[i];
      allfreqs[arr[i]]++;
  }
  sort(arr, arr+n);
  // if all one number, do all combos of that num, else do combos of x y's etc
  set<long long> all; 
  double avg = 0;
  for (int i=n-1; i>=n-a; i--){
      freqs[arr[i]]++;
      all.insert(arr[i]);
      avg += arr[i];
  }
  avg /= a;
  printf("%.6lf\n", avg);
  long long sum = 0;
  if (all.size() == 1){
      int many = allfreqs.find(arr[n-1])->second;
      for (int i=a; i<=b; i++){
         sum += choose(many, i);
      }
      
  }else{
      sum++;
      for (long long i : all){
          int freq = freqs.find(i)->second;
          sum *= choose(allfreqs.find(i)->second, freq);
      }
  }
  printf("%llu", sum);
  return 0; 
}
