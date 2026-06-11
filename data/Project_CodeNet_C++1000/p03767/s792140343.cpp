#include <bits/stdc++.h>
using namespace std;

int main() {
  int team;
  int num;
  long long kekka = 0;
  cin >> team;
  
  num = team * 3;
  vector<long long> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  sort(vec.begin(), vec.end(),greater<long long>());
  for(int i = 0; i < team; i++){
    kekka += vec.at(i * 2 + 1);
  }
  
  cout << kekka;
}
