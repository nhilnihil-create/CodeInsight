#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int A=200001;
  int Z;
  int N=s.size();
  for(int i=0;i<N;i++){
    if(s.at(i)=='A'&& i<A) A=i;
    if(s.at(i)=='Z') Z=i;
  }
  cout << Z-A+1 << endl;
}
