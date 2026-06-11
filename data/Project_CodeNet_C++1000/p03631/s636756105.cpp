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
  string t = s;
  reverse(s.begin(),s.end());
  if(s == t)cout << "Yes" << endl;
  else cout << "No" << endl;
}