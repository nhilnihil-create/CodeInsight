#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int x, y;
  cin >> x >> y;

  set<int> a = {1, 3, 5, 7, 8, 10, 12};
  set<int> b = {4, 6, 9, 11};
  set<int> c = {2};

  if ((a.find(x) != a.end() && a.find(y) != a.end()) || (b.find(x) != b.end() && b.find(y) != b.end()) || (c.find(x) != c.end() && c.find(y) != c.end())){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
}