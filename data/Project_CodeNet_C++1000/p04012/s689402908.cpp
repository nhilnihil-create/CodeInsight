#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string w;
  cin >> w;

  int cnt;
  for (int i = 0; i < w.size(); i++)
  {
    cnt = 0;
    for (int j = 0; j < w.size(); j++)
    {
      if (w.at(i) == w.at(j)){
        cnt += 1;
      }
    }
    if (cnt % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}