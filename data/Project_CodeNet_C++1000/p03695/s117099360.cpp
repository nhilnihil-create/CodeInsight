#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> b;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    int c=a.at(i)/400;
    if(c>7)
      c=8;
    b[c]++;
  }
  if(b.count(8)){
    if(b.size()==1)
      cout << 1 << " " << n << endl;
    else
      cout << b.size()-1 << " " << b.size()-1+b[8] << endl;
  }
  else
    cout << b.size() << " " << b.size() << endl;
}
         


