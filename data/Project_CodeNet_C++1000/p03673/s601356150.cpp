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
  ll dir = 1;
  vector<ll> res;
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    if(dir == 1)res.push_back(in);
    else res.insert(res.begin(),in);
    dir *= -1;
  }
  if(dir == -1)reverse(res.begin(),res.end());
  for(int i = 0;i < n - 1;i++)cout << res[i] << " ";
  cout << res[n - 1] << endl;
}