#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  
  if(a%2==0 || b%2==0 || c%2==0){
    cout << 0 << endl;
    return 0;
  }
  
  if(b<c)
    swap(b,c);
  if(a<b)
    swap(a,b);
  
  cout << b*c << endl;
  
  return 0;
}
