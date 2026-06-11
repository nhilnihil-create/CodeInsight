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
  cin >> n;
  int all = 0;
  vector<int> num(n);
  for(int i = 0;i < n;i++){
    cin >> num[i];
    all += num[i];
  }
  int res = 0;
  sort(num.begin(),num.end());
  if(all % 10 != 0)res = all;
  else{
  for(int i = 0;i < n;i++){
    if((all - num[i]) % 10 != 0){
      res = all - num[i];
      break;
    }
  }
  }
  cout << res << endl;
}