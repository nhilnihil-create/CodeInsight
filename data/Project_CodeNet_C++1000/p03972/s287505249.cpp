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
  int w, h;
  cin >> w >> h;
  int warr[w];
  int harr[h];
  pair<int, int> sorted[w+h];
  int cnt = 0;
  for (int i=0; i<w; i++){
      cin >> warr[i];
      sorted[cnt] = {warr[i], 0};
      cnt++;
  }
  for (int j=0; j<h; j++){
      cin >> harr[j];
      sorted[cnt] = {harr[j], 1};
      cnt++;
  }
  int wcnt = w+1;
  int hcnt = h+1;
  sort(sorted, sorted+w+h);
  long long res = 0;
  for (int i=0; i<w+h; i++){
      long long val = sorted[i].first;
      int which = sorted[i].second;
      if (which == 0){
          res += hcnt*val;
          wcnt--;
      }else{
          res += wcnt*val;
          hcnt--;
      }
  }
  cout <<res;
  return 0; 
}