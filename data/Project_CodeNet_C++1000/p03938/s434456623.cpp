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
  int a[n];
  int b[n];
  int rank[n];
  for (int i=0; i<n; i++){
      cin >> arr[i];
      arr[i]--;
      rank[arr[i]] = i+2;
  }
  a[0] = 1;
  b[0] = rank[0]-1;
  int vals[n];
  
  for (int i=1; i<n; i++){
      int aval = a[i-1];
      int bval = b[i-1];

      int newsum = rank[i];
      int nexta = aval+1;
      int nextb = bval-1;
      if (newsum < nexta+nextb){
          nextb -= nexta+nextb-newsum;
      }else if (newsum > nexta+nextb){
          nexta += newsum-nexta-nextb;
      }
      a[i] = nexta;
      b[i] = nextb;
  }
  int lowesta = 1000000000;
  for (int i=0; i<n; i++){
      lowesta = min(lowesta, a[i]);
  }
  if (lowesta <= 0){
      lowesta = abs(lowesta)+1;
  }else{
      lowesta = 0;
  }
  int lowestb = 1000000000;
  for (int i=0; i<n; i++){
      lowestb = min(lowestb, b[i]);
  }
  if (lowestb <= 0){
      lowestb = abs(lowestb)+1;
  }else{
      lowestb = 0;
  }
  for (int i=0; i<n; i++){
      a[i] += lowesta;
      b[i] += lowestb;
  }
  for (int i=0; i<n; i++){
      cout << a[i] << " ";
  }
  cout << '\n';
  for (int i=0; i<n; i++){
      cout << b[i] << " ";
  }
  return 0; 
}