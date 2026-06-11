#include<bits/stdc++.h>
using namespace std;

int main(void){
  int time, sum = 0;
  cin >> time;
  vector<vector<int>> num(time, vector<int>(2));
    
  for(int i = 0; i < time; i++){
    cin >> num.at(i).at(0) >> num.at(i).at(1);
    sum += num.at(i).at(1) - num.at(i).at(0) + 1;
  }
  cout << sum << endl;
}