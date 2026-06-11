#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  int n, m;
  vector<long> a, b, c, d;
  cin >> n >> m ;
  for(int i = 0; i < n; i++) {
    long tmp_a, tmp_b;
    cin >> tmp_a >> tmp_b;
    a.push_back(tmp_a);
    b.push_back(tmp_b);
  }

  for(int j = 0; j < m; j++) {
    long tmp_c, tmp_d;
    cin >> tmp_c >> tmp_d;
    c.push_back(tmp_c);
    d.push_back(tmp_d);
  }

  for(int i = 0; i < n; i++) {
    long min_diff = abs(a[i]-c[0]) + abs(b[i]-d[0]);
    int check_point = 0;
    for(int j = 1; j < m; j++) {
      long next_check_point = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if(next_check_point < min_diff) {
        min_diff = next_check_point;
        check_point = j;
      }
    }
    cout << check_point + 1 << endl;
  }
  return 0;
}
