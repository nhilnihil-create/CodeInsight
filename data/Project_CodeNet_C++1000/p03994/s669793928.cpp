#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  string s;
  int n = 0;
  cin >> s >> n;
  for(int i = 0;i < s.size();i++){
    if((int)('z' - s[i]) + 1 <= n && s[i] != 'a'){
      n -= (int)('z' - s[i]) + 1;
      s[i] = 'a';
      //cout << s[i] << endl;
    }
    //cout << i << " " << n << endl;
  }
  n %= 26;
  if(n > 0){
    for(int i = s.size() - 1;i >= 0;i--){
      if(s[i] != 'a'){
        s[i] += n;
        n = 0;
        break;
      }
    }
  }
  if(n > 0)s[s.size() - 1] += n;
  cout << s << endl;
  return 0;
}