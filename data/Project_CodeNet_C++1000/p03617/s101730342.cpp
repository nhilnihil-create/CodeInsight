#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  
  ll liters;
  cin >> liters;
  
  if (liters % 2 == 0) {
    cout << min(liters*q*4, min(liters*h*2, min(liters*s, liters/2*d))) << endl;
  } else {
    ll subtotal = min(4*q, min(2*h, s)); // buy 1 liter from 0.25, 0.5, or 1
    liters--;
    cout << subtotal + min(liters*q*4, min(liters*h*2, min(liters*s, liters/2*d))) << endl;
  }
  return 0;
}