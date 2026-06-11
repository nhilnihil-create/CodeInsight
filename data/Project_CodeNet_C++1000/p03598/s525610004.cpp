#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, K, x, dist;
  int val = 0;
  
  cin >> N >> K;
  
  for (int i=0; i<N; i++)
  {
    cin >> x;
    if (x - K < 0)
    {
      dist = K - x;
    }
    else
    {
      dist += x - K;
    }
    if(x > dist)
    {
      val += 2 * dist;
    }
    else
    {
      val += 2 * x;
    }
  }
  cout << val << endl;
}
