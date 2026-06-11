#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char op;
  string sa;
  cin >>sa;
  string a,b,c;
  for(int i=0;i<sa.size();i++)
  {
      if(sa[i]==',')sa[i]=' ';
  }
  istringstream s(sa);
  s >> a >> b >> c;
  cout<<a<<" "<<b<<" "<<c<<endl;
}
