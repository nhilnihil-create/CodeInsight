#include <bits/stdc++.h>
using namespace std;

int main(){
  const vector<int> group= {-1, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x,y;
  cin >> x >> y;

  string ans= (group.at(x)==group.at(y)) ? "Yes"
                                         : "No";

  cout << ans << endl;
}