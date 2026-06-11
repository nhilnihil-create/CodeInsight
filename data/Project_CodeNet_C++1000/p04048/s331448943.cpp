#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll func(ll a, ll b){
  if(a==b){
    return a;
  } else if(b < a){
    swap(a, b);
  }
  if(b%a==0){
    return 2*a*(b/a)-a;
  } else {
    return 2*a*(b/a)+func(a, b%a);
  }
}

int main(){
  ll n, x;
  cin >> n >> x;
  cout << n+func(n-x, x) << endl;
  return 0;
}
