#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string str;
  cin >> str;
  int k;
  cin >> k;
  rep(i, str.length()){
    if(str[i] != 'a' && 'z'+1-str[i] <= k){
      k -= 'z'+1-str[i];
      str[i] = 'a';
    }
  }
  k %= 26;
  str[str.length()-1] += k;
  cout << str << endl;
  return 0;
}