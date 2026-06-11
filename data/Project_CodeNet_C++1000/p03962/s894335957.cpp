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
  map<ll,ll> m;
  for(int i = 0;i < 3;i++){
    ll n = 0;
    cin >> n;
    m[n]++;
  }
  cout << m.size() << endl;
}