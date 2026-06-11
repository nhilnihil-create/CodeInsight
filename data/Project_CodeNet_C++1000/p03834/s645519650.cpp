#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> sumV(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  string s;
  cin >> s;
  for(int i = 0; i < 19; i++){
    if(i == 5 || i == 13){
      cout << " ";
    } else{
      cout << s[i];
    }
  }
}
