#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  int c;

  
  cin >> a >> b >> c;
  
  int m = max({a,b,c});
  
  vector<int> v = {a,b,c};
  sort(v.begin(), v.end());
  
  if(v[0] + v[1] == m){
    cout << "Yes";
 	}
  else{
  	cout << "No";
  }
  
}