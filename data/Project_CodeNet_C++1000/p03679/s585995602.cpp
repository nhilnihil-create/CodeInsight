#include<bits/stdc++.h>
using namespace std;
int main(){
  long x,a,b;cin>>x>>a>>b;
  cout<<  (b<=a?"delicious":(b<=a+x?"safe":"dangerous"))<<endl;
}

