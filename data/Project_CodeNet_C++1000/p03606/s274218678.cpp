#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> I(N);
  vector<int> r(N);
  
  for (int i = 0; i < N; i++) {
	cin >> I.at(i) >> r.at(i);
  }//I,r出力
  int c =0;
  for (int i = 0; i < N; i++) {
    c = c +r.at(i) - I.at(i) +1;
  }//１組ごとの人数カウント
 cout << c << endl;
}