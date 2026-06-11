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
  int n = 0;
  string s;
  cin >> n >> s;
  int now = 0;
  int res = 0;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'I')now++;
    else now--;
    res = max(res,now);
  }
  cout << res << endl;
}