#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string n;
  cin >> n;

  string n1 =n;

  int s = 3;

  rep(i,s){
    n1.at(i) = n.at(s - i - 1);
    if(n1.at(i) != n.at(i)){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
