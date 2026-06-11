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
  vi a;
  int n;
  cin >> n;
  
  while (n--) {
    int k;
    cin >> k;
    
    a.pb(k);
  }
  
  int count = 0;
  
  for (int i = 0; i < a.size(); ++i) {
    if (a[a[i]-1] == i+1) {
      count++;
    }
  }
  
  cout << count/2 << endl;
  return 0;
}