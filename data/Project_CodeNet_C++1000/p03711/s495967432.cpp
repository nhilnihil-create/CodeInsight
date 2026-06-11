#include<iostream>
using namespace std;
int main()
{
  int x,y,g1,g2;
  cin >> x >> y;
  if(x==4||x==6||x==9||x==11)
    g1=2;
  else if(x==2)
    g1=3;
  else
    g1=1;
  if(y==4||y==6||y==9||y==11)
    g2=2;
  else if(y==2)
    g2=3;
  else
    g2=1;
  if(g1==g2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}