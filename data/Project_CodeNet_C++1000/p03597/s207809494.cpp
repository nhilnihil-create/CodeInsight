#include <bits/stdc++.h>
using namespace std;

int main() {
  int rowNum,drawNum;
  cin >> rowNum;
  cin >> drawNum;
  
  int cellNum = rowNum * rowNum;
  int restCellNum = cellNum - drawNum;
  cout << restCellNum << endl;
}