#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  string s;
  cin >> s;
  vector<int> num(26);
  vector<int> counter(10000);
  rep(i,26) num.at(i) = 'a' + i;
  rep(i,s.size()) rep(j,26){
    if(s.at(i) == num.at(j)) counter.at(num.at(j))++;
  } 
  for(int i = 0;i<26;i++){
    string ans = "None";
    if(counter.at(num.at(i)) == 0){
      ans = num.at(i);
      cout << ans << endl;
      break;
    }
    if(i == 25) cout << ans << endl;

  }

}