#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<long long> c(n);
  for(int i = 0; i < n; i++){
    cin >> c.at(i);
  }
  sort(c.rbegin(), c.rend());
  long long a = 0, b = 0;
  for(int i = 0; i < n - 1; i++){
    if(c.at(i) == c.at(i+1)){
      if(!a){
        a = c.at(i);
        i = i + 1;
      }
      else if(!b){
        b = c.at(i);
        break;
      }
    }
  }
  cout << a * b << endl;
}
      
    

