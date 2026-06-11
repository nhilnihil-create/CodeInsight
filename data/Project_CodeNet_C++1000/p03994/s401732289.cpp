#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;

  for(int i = 0;i < s.size();i++){
    int margin = (int)(26 - s[i] + 'a');
    if(margin <= k && s[i] != 'a'){
      s[i] = 'a';
      k -= margin;
    }
  }

  if(k != 0)s[s.size() - 1] = 'a' + (s[s.size() - 1] - 'a' + k) % 26;  

  cout << s << endl;
}