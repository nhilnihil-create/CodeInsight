#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int math_number = 0;
  cin >> math_number;
  
  int total_math_number = math_number * math_number;
  
  int white_math;
  cin >> white_math;
  
  int black_math = total_math_number - white_math;
  
  cout << black_math << endl;
}