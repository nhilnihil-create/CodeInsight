/*
corner case (aaza, 26), (aaaa, 10000000)
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

string s;
int k;

int main(){
  cin >> s >> k;
  int n = s.size();
  rep(i, n){
    if(s.at(i) == 'a') continue;
    int c = s.at(i) - 'a';
    if(k >= (26 - c)){
      k -= (26 - c);
      s.at(i) = 'a';
    }
  }
  k %= 26;
  s.at(n - 1) += k;
  cout << s << endl;
  return 0;
}