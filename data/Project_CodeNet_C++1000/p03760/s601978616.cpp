#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main(){
  string O, E;
  cin >> O >> E;

  vector<char> Ans((O.size()+E.size()), {});

  rep(i, 0, Ans.size()) {
    if (i%2 == 0) {
      Ans.at(i) = O[i/2];
    } else {
      Ans.at(i) = E[i/2];
    }
  }

  rep(i, 0, Ans.size()) {
    cout << Ans.at(i);
  }
  cout << endl;
}
