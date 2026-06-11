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
  for(int i = 0;i < w + 2;i++)cout << "#";
  cout << endl;
  for(int i = 0;i < h;i++){
    string s;
    cin >> s;
    cout << "#" << s << "#" << endl;
  } 
  for(int i = 0;i < w + 2;i++)cout << "#";
  cout << endl;
}