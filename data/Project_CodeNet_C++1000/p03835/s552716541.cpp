#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  int i, j, k;
  int n, s, sum = 0;
  cin>>n>>s;
  sum = 0;

  for(i = 0; i<=n; i++)
  {
      for(j = 0; j<=n; j++)
      {
          k = s - i - j;
          if(0<=k && k<=n) sum++;
      }
  }
  cout<<sum<<endl;
      return 0;
}
