#include <bits/stdc++.h>
using namespace std;

int main() {
  int city_num, road_num;
  cin >> city_num >> road_num;
  
  vector<int> city_road(city_num);

  for (int cnt=0; cnt < road_num; ++cnt) {
    int a,b;
    cin >> a >> b;
    city_road.at(a-1) += 1;
    city_road.at(b-1) += 1;
  }

  for (int cnt=0; cnt < city_num; ++cnt) {
    cout << city_road.at(cnt) << endl;
  }

  return 0;
}