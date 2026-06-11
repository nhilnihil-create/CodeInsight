#include <bits/stdc++.h>
using namespace std;

int main() {
 int a , b ;
 cin >> a >> b;
 string ans = "Impossible";
  if(a%3 == 0)
    ans = "Possible";
  if(b%3 == 0)
    ans = "Possible";
  if((a+b)%3 == 0)
    ans = "Possible";
  
  cout << ans;
  
 
}
