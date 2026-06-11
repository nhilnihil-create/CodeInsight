#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  int i, j, h, w, n;
  cin>>h>>w;
  n = 2;
  char a[h][w];
  for(i = 0; i<h; i++)
  {
      for(j = 0 ; j<w; j++)
      {
           cin>>a[i][j];
      }
  }
  //cout<<endl;
  for(i = 0; i<h; i++)
  {  while(n--)
  {
      for(j = 0; j<w; j++)
      {
          cout<<a[i][j];
      }
      cout<<endl;

  }
  n = 2;
  }




  return 0;
}
