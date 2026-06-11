#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  string s;
  cin>>s;
  if(int(s.size()) >= 4 && s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I'){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}