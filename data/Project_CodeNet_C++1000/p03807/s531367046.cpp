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
  ll n;
  cin >> n;
  ll odd = 0;
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    if(in % 2 == 1)odd++;
  }
  if(odd % 2 == 1)cout << "NO" << endl;
  else cout << "YES" << endl;
}