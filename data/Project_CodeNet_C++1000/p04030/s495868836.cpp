#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  string res;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'B'){
      if(res.size() == 0)continue;
      res.erase(res.begin() + res.size() - 1);
    }
    else res += s[i];
  }
  cout << res << endl;
}