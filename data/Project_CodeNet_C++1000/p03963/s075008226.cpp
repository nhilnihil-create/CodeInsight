#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long N, K;
  cin >> N >> K;
  cout << ((unsigned long long)(K * pow((K - 1), (N - 1)))) << endl;
  getchar();
}