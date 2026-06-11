#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n ;
  cin >> n;
  
  int c=0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
    if(vec.at(i)%2==1){
      c++;
    }
  }
 
  if(c%2==1){
  cout << "NO" << endl;
  }
  
  else{
    cout << "YES" << endl;
  }
}