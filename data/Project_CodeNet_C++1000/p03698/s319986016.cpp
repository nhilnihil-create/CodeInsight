#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  string s; cin >> s;
  map<char,int> mp;
  rep(i,s.size()){
    char c = s[i];
    mp[c] += 1;
    if (mp[c] >= 2){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;

	return 0;
}

