#include <bits/stdc++.h>
using namespace std;

int main() {
  int city_num, road_num;
  cin >> city_num >> road_num;
  vector<int> cnt(city_num);

  for(int i=0; i < road_num; i ++) {
    int a, b;
    cin >> a >> b;
    cnt.push_back(a);
    cnt.push_back(b);
  }

  for(int i=1; i <= city_num; i++) {
    cout << count(cnt.begin(),cnt.end(), i) << endl;
  }
}