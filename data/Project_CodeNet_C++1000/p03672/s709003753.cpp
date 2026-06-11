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
  ll si = s.size();
  ll res = 0;
  for(int i = 0;i < si / 2 - 1;i++){
    string a = s.substr(0,i + 1);
    string b = s.substr(i + 1,i + 1);
    //cout << a << " " << b << endl;
    if(a == b)res = max(res,(ll)i);
  }
  cout << (res + 1) * 2 << endl;
}