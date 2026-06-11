#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  int i, j, k, a = 0, b = 0;
  int sx, sy, tx, ty;
  cin>>sx>>sy>>tx>>ty;

  for(i = sy; i<ty; i++)
  {
      cout<<"U";
      a++;
  }
  for(i = sx; i<tx; i++)
  {
      cout<<"R";
      b++;
  }
  while(a--)
  {
      cout<<"D";
  }
  while(b--)
  {
      cout<<"L";
  }
  cout<<"L";
  for(i = sy; i<=ty; i++)
  {
      cout<<"U";
      a++;
  }
  for(i = sx; i<=tx; i++)
  {
      cout<<"R";
      b++;
  }
  cout<<"D";
  cout<<"R";
  a++;
  b++;
  while(a--)
  {
      cout<<"D";
  }
  while(b--)
  {
      cout<<"L";
  }
  cout<<"U";







      return 0;
}
