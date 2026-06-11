#include <bits/stdc++.h>
using namespace std;
  
int main(){
  vector<int>n(3);
  for(int i=0;i<3;i++)
    cin >> n.at(i);
  sort(n.begin(),n.end());
  vector<int>m = {5,5,7};
  if(n==m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}