#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string a, b, c;
  cin >> a >> b >> c;

  string initial = a.substr(0,1) + b.substr(0,1) + c.substr(0,1);

  for (int i = 0; i < initial.size(); i++){
    if (islower(initial.at(i))){
      initial.at(i) = toupper(initial.at(i));
    }
  }

  cout << initial << endl;

}