#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
  ll N;
  cin >> N;

  ll K, sum;
  for(ll i = 1; i <= N; i++)
  {
	if(i * (i + 1) / 2 >= N)
	{
	  K = i;
	  sum = i * (i + 1) / 2;
	  break;
	}
  }

  ll remove = -1;
  if(sum > N)
  {
	remove = sum - N;
  }

  for(int i = 1; i <= K; i++)
  {
	if(i != remove)
	{
	  cout << i << endl;
	}
  }  
}
