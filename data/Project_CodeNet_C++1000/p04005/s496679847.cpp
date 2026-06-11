#include<iostream>
using namespace std;
int main(){
  long long int a,b,c,odd=0;
  cin >> a >> b >> c;
  if(a%2==1)odd++;
  if(b%2==1)odd++;
  if(c%2==1)odd++;
  if(odd<3)cout << 0;
  else cout << min(min(a*b,b*c),a*c);
}
