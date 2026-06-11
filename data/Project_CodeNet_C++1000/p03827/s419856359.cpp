#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int x = 0;
  int max = 0;

  for (int i = 0; i < N; i++)
  {
    if (S.at(i) == 'I'){
      x += 1;
    }
    else if (S.at(i) == 'D')
    {
      x -= 1;
    }

    if (x > max) max = x;
    
  }
  cout << max << endl;
}