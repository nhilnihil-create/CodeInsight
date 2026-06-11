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
  int a = 0;
  int z = 0;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'A'){
      a = i;
      break;
    }
  }
  for(int j = s.size() - 1;j >= 0;j--){
    if(s[j] == 'Z'){
      z = j;
      break;
    }
  }
  //cout << z << a << endl;
  cout << z - a + 1 << endl;
}