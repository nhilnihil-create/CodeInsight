#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(9);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    a.at(min(x/400,8))++;
  }
  
  int p=0,q=a.at(8);
  for(int i=0;i<8;i++){
    p+=(a.at(i)>0);
  }
  cout << max(p,1) << " " << p+q << endl;
}