#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  for(int i = 1;; i++) {
    if(i * (i + 1) / 2 >= N) {
      for(int j = i; j >= 1; j--) {
        if(N - j >= 0) {
          cout << j << endl;
          N -= j;
        }
      }
      break;
    }
  }
}
