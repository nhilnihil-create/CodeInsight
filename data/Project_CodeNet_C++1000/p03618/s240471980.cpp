#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  vector<ll> count(27);
  for(int i = 0;i < 26;i++)count[i] = 0;
  //cout << 'a' - 'a' << endl;
  for(int i = 0;i < s.size();i++){
    count[s[i] - 'a']++;
  }
  ll res = 0;
  res = s.size() * (s.size() - 1) / 2;
  for(int i = 0;i < 26;i++){
    res -= count[i] * (count[i] - 1) / 2;
    //cout << count[i] << " ";
  }
  //cout << endl;
  res++;
  cout << res << endl;
  return 0;
}