#include<iostream>
#include<cmath>
using namespace std;

int main () {
  int N, K;
  cin >> N >> K;
  int count = K * pow(K - 1, N - 1);
  
  cout << count << '\n';
}