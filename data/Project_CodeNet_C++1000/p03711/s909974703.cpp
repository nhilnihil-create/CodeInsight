#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
int main() {
  cout << fixed << setprecision(10);
  int x,y;
  cin >> x >> y;
  vector<int> a = {1,3,1,2,1,2,1,1,2,1,2,1};
  if(a.at(x-1)==a.at(y-1)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
