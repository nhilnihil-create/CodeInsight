#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int N=s.size();
  int a=-1;
  int z=-1;
  for (int i=0; i < N; i++){
    if ((a==-1) && (s[i]=='A')) a=i;
    if (s[i]=='Z') z=i;
  }
  cout << z-a+1 << endl;
}