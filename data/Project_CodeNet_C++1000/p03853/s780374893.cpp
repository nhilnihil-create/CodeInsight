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
  ll h,w;
  cin >> h >> w;
  vector<string> c(h);
  for(int i = 0;i < h;i++)cin >> c[i];
  for(int i = 0;i < h*2;i++){
    for(int j = 0;j < w;j++){
      cout << c[i / 2][j];
    }
    cout << endl;
  }
}