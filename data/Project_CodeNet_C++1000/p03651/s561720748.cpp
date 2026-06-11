#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> vec;
  int biggest = 0;
  rep(i, n){
    int num;
    cin >> num;
    biggest = max(biggest, num);
    vec.push_back(num);
  }
  int gcdNum = vec[0];
  for(int i=1; i<n; i++){
    gcdNum = gcd(gcdNum, vec[i]);
  }
  if(k % gcdNum == 0 && k <= biggest) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
  
  