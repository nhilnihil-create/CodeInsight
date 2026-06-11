#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  vector<int> n(3);
  rep(i,3){cin >> n[i];}
  int max = *max_element(n.begin(),n.end());
  cout << n[0]+n[1]+n[2]-max << endl;
}