#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  string s;
  cin>>s;
  ll i, a, z, n, j = 1, k = 1;
  n = s.size() - 1;
  for(i = 0; i<=n; i++)
  {
      if(s[i] == 'A' && j == 1)
      {
          a = i;
          j--;
      }
      if(s[n - i] == 'Z' && k == 1)
      {
          z = n - i;
          k--;
      }

  }
  cout<<z - a + 1<<endl;

return 0;
}

