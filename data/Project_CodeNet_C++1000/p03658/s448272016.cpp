#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >>n>>k;
  vector<int>vec(n);
  for(int i=0;i<n;i++) {
    cin >>vec.at(i);
  }
  stable_sort(vec.begin(),vec.end(),greater<int>());
  int p=0;
  for(int i=0;i<k;i++){
    p+=vec.at(i);
  }
  cout << p<<endl;
}
