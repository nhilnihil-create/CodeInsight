#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  if(abs(y-x)<abs(z-x))cout<<"A";
  else cout << "B";
}
