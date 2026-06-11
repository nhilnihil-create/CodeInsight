#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B,C; cin >> A >> B >> C;
  if(A.back()==B.front() && B.back()==C.front()) cout << "YES" << endl;
  else cout << "NO" << endl;
}