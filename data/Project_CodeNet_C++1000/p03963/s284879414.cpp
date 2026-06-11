#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  //printf("%d", K*pow(K-1, N-1));
  cout << (int)(K * pow(K-1, N-1)) << endl;
}