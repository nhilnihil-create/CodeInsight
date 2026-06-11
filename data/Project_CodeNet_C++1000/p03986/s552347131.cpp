#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A;cin >> A;
  long long s=0,t=0;
  for (int i=0;i<A.size();i++) {
    if (A[i]=='S') s++;
	else if (s>0) s--;
	else t++;
  }
  cout << s+t << endl;
  
}