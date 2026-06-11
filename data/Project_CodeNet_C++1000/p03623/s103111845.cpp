#include<iostream>
using namespace std;
int main()
{
  int point, a, b;
  cin>>point>>a>>b;
  
  int dist, dist1;
  
  if(a > point)
    dist = a-point;
  else if (a < point)
    dist = point - a;
  
  if(b > point)
    dist1 = b - point;
  else if(point > b)
    dist1 = point - b;
  
  if(dist > dist1)
    cout<<"B";
  else
    cout<<"A";
  return 0;
}