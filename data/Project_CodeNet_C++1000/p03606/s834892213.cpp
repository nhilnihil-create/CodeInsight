#include <bits/stdc++.h>
using namespace std;

int main() {
				    // *constraint*
  int N,l,r;    	// 1<=N<=1000
         		    // 1<=li<=ri<=100000
  				    // 同じ席に複数の人が座ることはなく，入力はすべて整数
  int sum = 0;
  cin  >> N;
  bool hasY = false;
  int i = 1;
  while (i <= N) {
    cin >> l >> r;
    sum += (r - l + 1);
    i ++;
  }
  
  cout << sum << endl;
}
