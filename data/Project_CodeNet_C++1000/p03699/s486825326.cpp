#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec;
  int sum = 0;
  rep(i, n){
    int num;
    cin >> num;
    sum += num;
    vec.push_back(num);
  }
  if(sum % 10 != 0){
    cout << sum << endl;
    return 0;
  }
  sort(all(vec));
  rep(i, n){
    if(vec[i] % 10 != 0){
      cout << sum - vec[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
    