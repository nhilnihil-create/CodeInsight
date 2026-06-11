#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>
#include <stack>

using namespace std;
const long long P = 1000000007;
const long long INF = 1LL << 60;

double dist(double x1,double y1, double x2, double y2) {
  double res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  return res;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  int flag = 0;
  for(int i = 0; i < n-1; i++) {
    if(flag == 0) {
      if(a[i] < a[i+1]) {flag = 1;}
      else if(a[i] > a[i+1]) {flag = -1;}
    }
    else if(flag == 1) {
      if(a[i] > a[i+1]) {
        flag = 0;
        count++;
      }
    }
    else if(flag == -1) {
      if(a[i] < a[i+1]) {
        flag = 0;
        count++;
      }
    }
  }
  cout << count+1 << endl;
  return 0;
}
