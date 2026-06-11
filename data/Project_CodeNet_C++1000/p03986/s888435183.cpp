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
  int res = 0;
  res = s.size();
  int count = 0;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'S')count++;
    if(s[i] == 'T'){
      if(count > 0){
        count--;
        res -= 2;
      }
    }
  }
  cout << res << endl;
}