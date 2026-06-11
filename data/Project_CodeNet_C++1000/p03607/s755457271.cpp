#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vl = vector<ll>;  // long longの1次元の型に vl という別名をつける
using vvl = vector<vl>; // long longの2次元の型に vvl という別名をつける
int MOD = 1000000007; //10^9 + 7

// 無限大の値
const ll  lINF = 1LL << 60;
const int iINF = 1 << 29;

int main(void){
  int n;
  cin >> n;

  vi a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());

  int i=0,ans=0;
  
  while(i <n){
    int now=a[i], flag=0;
    while(a[i]==now && i<n){
      i++;
      flag = 1 - flag; 
    }
    ans += flag;
  }

  cout << ans << endl;
  return 0;
}