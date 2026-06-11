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
  ll n = 0;
  cin >> n;
  ll four = 0;
  ll nottwo = 0;
  for(int i = 0;i < n;i++){
    ll m = 0;
    cin >> m;
    if(m % 4 == 0)four++;
    else if(m % 2 == 1)nottwo++;
  }
  if(n % 2 == 1 && nottwo == four + 1){
    if(nottwo + four == n)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else{
    if(four >= nottwo)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}