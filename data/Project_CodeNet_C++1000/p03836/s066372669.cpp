#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  const int x=c-a,y=d-b;
  cout<<string(x,'R')<<string(y,'U');
  cout<<string(x,'L')<<string(y,'D');
  cout<<'D'<<string(x+1,'R')<<string(y+1,'U')<<'L';
  cout<<'U'<<string(x+1,'L')<<string(y+1,'D')<<'R';
}
