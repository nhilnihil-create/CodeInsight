#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<int> xs(N);
  for(int i = 0; i < N; i++)
  {
	cin >> xs[i];
  }

  vector<int> vs;
  for(int i = 0; i < N; i++)
  {
	vs.push_back(i);
  }

  ll answer = 1;
  stack<ll> s;
  int index = 0;

  for(int i = 0; i < N; i++)
  {
	while(index < N && xs[index] >= 2 * s.size() + 1)
	{
	  s.push(xs[index++]);
	}
	if(index < N)
	{
	  s.push(xs[index++]);
	}
	
	answer *= s.size();
	answer %= 1000000007;
	s.pop();
  }
  cout << answer << endl;
}
