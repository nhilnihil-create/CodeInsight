#include <bits/stdc++.h>
using namespace std;
 


int main() {
long long a,b,c;
  cin>>a>>b>>c;
  vector<long long> vec(3);
  vec[0]=a;
  vec[1]=b;
  vec[2]=c;
  sort(vec.begin(), vec.end()); 
if(a % 2 != 0 && c % 2 != 0 && b % 2 != 0 ){
  cout << vec[0] * vec[1] <<endl;
  
}
  else cout << "0" <<endl;
}