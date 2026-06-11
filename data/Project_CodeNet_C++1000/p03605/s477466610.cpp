#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a;std::cin>>a;
  int x=a%10,y=a/10;
  if(x==9||y==9)std::cout<<"Yes";
  else cout<<"No";
  return 0;
}