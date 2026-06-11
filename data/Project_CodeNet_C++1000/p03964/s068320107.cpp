#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;
const int mod = 1000000007;


int main(){
  int N;
  cin >> N;
  ll A,B;
  A = B = 1;
  for(int i=0; i<N; i++){
    int a,b;
    cin >> a >> b;
    ll n;
    n = max((A+a-1)/a,(B+b-1)/b);
    A = n*a;
    B = n*b;
  }
  cout << A+B << endl;

  return 0;
}
