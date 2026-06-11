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
  
  long long h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int> > v;
  set<pair<int, int> > have;
  for (int i=0; i<n; i++){
      int x, y;
      cin >> x >> y;
      have.emplace(x, y);
      v.emplace_back(x, y);
  }
  long long ones[10] = {0}; // don't count 0's
  for (pair<int, int> p : v){
      int x = p.first;
      int y = p.second;
      for (int i=x-2; i<x+1; i++){
          for (int j=y-2; j<y+1; j++){
              int cnt = 0;
              for (int k=0; k<9; k++){
                  int newx = i+k/3;
                  int newy = j+k%3;
                  if (newx <= 0 || newy <= 0 || newx > h || newy > w){
                      cnt = 0;
                      break;
                  }
                  if (have.count({newx, newy})){
                      cnt++;
                  }
              }
              ones[cnt]++;
          }
      }
  }
  long long full = 0;
  for (int i=1; i<=9; i++){
      ones[i] /= i;
      full += ones[i];
  }
  cout << (h-2)*(w-2)-full << '\n';
  for (int i=1; i<=9; i++){
      cout << ones[i] << '\n';
  }
  return 0; 
}