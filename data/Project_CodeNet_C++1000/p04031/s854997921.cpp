#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double s=0;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    s += a.at(i);
  }
  s/=n;
  int m=round(s),c=0;
  for(int i=0;i<n;i++)
    c+=pow(a.at(i)-m,2);
  cout << c << endl;
}