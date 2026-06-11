#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> n(3); cin>>n[0]>>n[1]>>n[2];
  sort(n.begin(),n.end());
  if(n[2]==n[0]+n[1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}