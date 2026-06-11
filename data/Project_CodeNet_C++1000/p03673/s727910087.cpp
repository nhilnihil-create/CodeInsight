#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=0;i<n;i++){
    if(i<(n+1)/2)
      cout << a.at(n-1-i*2);
    else
      cout << a.at((i-(n+1)/2)*2+n%2);
    if(i!=n-1)
      cout << " ";
  }
  cout << endl;
  return 0;
}