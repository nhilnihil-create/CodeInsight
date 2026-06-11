#include <bits/stdc++.h>
using namespace std;
 
int main() {
 	int A;
  	int B;
  	int C;
  	int D;
  	int Sum1; /* 1つ目の長方形の面積 */
  	int Sum2; /* 2つ目の長方形の面積*/
  
  	cin >> A >> B >> C >> D;
  	Sum1 = A * B;
  	Sum2 = C * D;
  	
  	cout << max(Sum1,Sum2) << endl;
  }