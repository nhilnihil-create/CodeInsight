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
  int l = 0;
  cin >> n >> l;
  vector<int> a(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  ll ma = 0;
  ll num = 0;
  for(int i = 0;i < n - 1;i++){
    if(ma < a[i] + a[i + 1]){
      ma = a[i] + a[i + 1];
      num = i;
    }
  }
  if(ma < l){
    cout << "Impossible" << endl;
  }
  else{
    cout << "Possible" << endl;
    for(int i = 0;i < num;i++)cout << i + 1<< endl;
    for(int i = n - 1;i >= num + 1;i--)cout << i<< endl;
  }
  return 0;
}