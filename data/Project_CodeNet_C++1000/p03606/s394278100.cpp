#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  ll N;
  cin >> N;
  ll a = 0;
  for(int i = 0; i < N; i++){
    ll  l,r;
    cin >> l >> r;
    a = a + r - l + 1;
  }
  cout << a << endl;
}
