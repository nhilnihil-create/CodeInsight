#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long a[1000000];
long long n;

long long count(long long sum)	{
  long long changes = 0;
  for (int i = 1; i < n; i++)	{
    if (sum > 0)	{
      sum += a[i];
      if (sum >= 0)	{
        changes += abs(sum) + 1;
        sum = -1;
      }
    }
    else	{
      sum += a[i];
      if (sum <= 0)	{
        changes += abs(sum) + 1;
        sum = 1;
      }
    } 
  }
  return changes;
}



int main()	{
  cin >> n;
  long long sum = 0;
  long long changes = 1e18;
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
  }
  if (a[0] == 0)	{
    changes = min(changes, count(-1) + 1);
    changes = min(changes, count(1) + 1);
  }
  else	{
    changes = min(changes, count(a[0]));
    if (a[0] > 0)	{
      changes = min(changes, count(-1) + abs(a[0]) + 1);
    }
    else	{
      changes = min(changes, count(1) + abs(a[0]) + 1);
    }
  }
  cout << changes << endl;
  return 0;
}