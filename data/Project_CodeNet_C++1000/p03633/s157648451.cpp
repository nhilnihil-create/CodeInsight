#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a , b) * b;
}
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    ll a , b = 1;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a;
        b = lcm(a , b);
    }
    cout << b;
}