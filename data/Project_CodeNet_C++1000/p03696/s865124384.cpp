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
  ll n = 0;
  cin >> n;
  string s;
  cin >> s;
  ll open = 0;
  ll close = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == '(')open++;
    else{
      if(open > 0)open--;
      else close++;
    }
  }
  for(int i = 0;i < close;i++)s = '(' + s;
  for(int i = 0;i < open;i++)s = s + ')';
  cout << s << endl;
}