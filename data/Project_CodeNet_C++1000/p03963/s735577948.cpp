#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K,N;
  cin >> N >> K;
  int ans = K;
  
  if(N > 1)
  {
    for(int i=0; i<N-1; i++)
    {
      ans *= K-1;
    }
  }  
  cout << ans;
}
  
  