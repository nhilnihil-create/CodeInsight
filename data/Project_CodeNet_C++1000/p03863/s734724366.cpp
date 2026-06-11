#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a;
  getline(std::cin,a);
  bool f1=a.size()%2==1;
  bool f2=a[0]==a[a.size()-1];
  if(f1^f2)cout<<"First";
  else cout<<"Second";
  return 0;
}