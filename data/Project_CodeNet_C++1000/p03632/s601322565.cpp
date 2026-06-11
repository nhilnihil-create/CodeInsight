#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,d;
  cin >> a >> b >> c >> d;
if(b<=c | a>=d)cout << 0 << endl;  
else{
int s=max(a,c);
int t=min(b,d);
  cout << t-s << endl;
}
}  
