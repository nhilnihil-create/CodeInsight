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
  ll n, k;
  cin >> n >> k;
  
  ll ways = k;
  
  for (int i = 1; i < n; ++i) {
    ways *= (k-1);
  }
  
  cout << ways << endl;
  return 0;
}