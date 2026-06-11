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
    if(i % 2 == 0)res = res + s[i];
  }
  cout << res << endl;
}