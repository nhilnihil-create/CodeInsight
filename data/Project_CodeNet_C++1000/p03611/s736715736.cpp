#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> b;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    b[a.at(i)]++;
  }
  sort(a.begin(), a.end());
  int f=a.at(0);
  int l=a.at(n-1);
  int max=0;
  for(int i=f;i<=l;i++){
    if(b[i]+b[i+1]+b[i+2]>max)
      max=b[i]+b[i+1]+b[i+2];
  }
  cout << max << endl;
  
}