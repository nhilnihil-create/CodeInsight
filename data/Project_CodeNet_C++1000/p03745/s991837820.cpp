#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0;i<n;i++) {
    cin>>a.at(i);
  }
  int count=0;
  for(int i=0;i<n;i++) {
    while(i+1<n && a.at(i) == a.at(i+1)) ++i;
    if(i+1<n && a.at(i)<a.at(i+1)) {
      while(i+1<n && a.at(i) <= a.at(i+1)) ++i;
    } else if(i+1<n && a.at(i) > a.at(i+1)) {
      while(i+1<n && a.at(i) >= a.at(i + 1)) ++i;
    }
    count++;
  }
  cout << count << endl;
}