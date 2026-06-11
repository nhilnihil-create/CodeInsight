#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> b(0);
  vector<int> c(0);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(i%2) b.push_back(a);
    else c.push_back(a);
  }
  if(n%2==0){
    reverse(b.begin(),b.end());
    for(int i=0;i<b.size();i++) cout << b.at(i) << " ";
    for(int i=0;i<c.size();i++) cout << c.at(i) << " ";
  }
  else{
    reverse(c.begin(),c.end());
    for(int i=0;i<c.size();i++) cout << c.at(i) << " ";
    for(int i=0;i<b.size();i++) cout << b.at(i) << " ";
  }
}