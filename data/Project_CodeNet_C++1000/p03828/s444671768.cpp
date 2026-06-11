#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool IsPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
    {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main(){

  int n;
  cin >> n;
  vector<int> p;

  for (int i = 1; i <= n; i++) {
    if (IsPrime(i)) {
      p.push_back(i);
    }
  }

  vector<ll> sum(p.size());

  /*for (int i = 0; i < p.size(); i++) {
    cout << p.at(i) << endl;
  }*/

  //cout << '\n';

  for (int i = 0; i < p.size(); i++) {
    int t = p.at(i);
    int s = p.at(i);
    while (n >= t) {
      sum.at(i) += n/t;
      t*=s;
    }
    //cout << sum.at(i) << endl;
  }

  ll a = 1;
  for (int i = 0; i < sum.size(); i++) {
    a *= (sum.at(i)+1);
    a %= 1000000007;
  }
  std::cout << a << '\n';

}
