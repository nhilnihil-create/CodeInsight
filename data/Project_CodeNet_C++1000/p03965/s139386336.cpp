#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define ll long long
#define rn(i,n) for(int i=1;i<=n;i++)

int main() {

  string s;
  cin>>s;
  int cnt=0;
  r(i,s.size())
    if(s.at(i)=='p')cnt++;

  cout<< s.size()/2 -cnt <<endl;


return 0;
}
