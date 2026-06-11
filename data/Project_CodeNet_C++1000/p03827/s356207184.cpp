#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  int x = 0;
  int n, i, j = 0;
  cin>>n;
  int a[n];
  for(i = 0; i<n; i++)
  {
      char a;
      cin>>a;
      if(a == 'I') x++;
      else x--;

      j = max(j, x);
  }
  cout<<j<<endl;



  return 0;
}

