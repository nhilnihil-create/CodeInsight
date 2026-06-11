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
  vector<int> count(26);
  for(int i = 0;i < 26;i++)count[i] = 0;
  for(int i = 0;i < s.size();i++){
    count[s[i] - 'a']++;
  }
  for(int i = 0;i < 26;i++){
    if(count[i] == 0){
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}