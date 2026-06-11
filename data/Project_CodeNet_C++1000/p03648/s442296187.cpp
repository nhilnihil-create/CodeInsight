#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void simulate_rev(vector<ll> &vs, int idx)
{
  for (int i = 0; i < vs.size(); i++)
  {
	if (i == idx)
	{
	  vs[i] += vs.size();
	}
	else
	{
	  vs[i]--;
	}
  }
}

int main()
{
  ll k;
  cin >> k;

  vector<ll> ary(50, 0);
  for (int i = 0; i < min(k, 50ll); i++)
  {
	ary[i] = 50 - i;
  }
  if (k > 50)
  {
	for (int i = 0; i < 50; i++)
	{
	  ary[i] += k / 50 - 1;
	}
	for (int i = 0; i < k % 50; i++)
	{
	  simulate_rev(ary, 49 - i);
	}
  }
  
  cout << 50 << endl;
  for (int i = 0; i < 50; i++)
  {
	if (i > 0) cout << " ";
	cout << ary[i];
  }
  cout << endl;
}
