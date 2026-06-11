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
  int place[200001];
  for (int i=0; i<n; i++){
      cin >> arr[i];
      place[arr[i]] = i;
  }
  long long res = 0;
  set<int> indexs;
  for (int i=1; i<=n; i++){
      int myind = place[i];
      int bottom = 0;
      int top = n-1;
      auto lower = indexs.lower_bound(myind);
      if (lower != indexs.begin()){
          lower--;
          bottom = *lower+1;
      }
      auto upper = indexs.upper_bound(myind);
      if (upper != indexs.end()){
          top = *upper-1;
      }
      long long diff1 = myind-bottom+1;
      long long diff2 = top-myind+1;
      //cout << bottom << " " << top << endl;
      res += i*diff1*diff2;
      indexs.insert(place[i]);
  }
  cout << res;
  return 0; 
}