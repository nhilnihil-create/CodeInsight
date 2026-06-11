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
  string a,b;
  cin >> a >> b;
  string s;
  for(int i = 0;i < (int)(a.size() + b.size());i++){
    if(i % 2 == 0)s += a[i / 2];
    else s += b[i / 2];
  }
  cout << s << endl;
}