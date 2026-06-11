#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define ll long long

using namespace std;
int mod = 1000000007;

int X;
int main() {
  cin >> X;
  int i=1;
  int sum = 0;
  while(true) {
    sum += i;
    if (sum >= X) {
      break;
    }
    i++;
  }
  cout << i << endl;
}