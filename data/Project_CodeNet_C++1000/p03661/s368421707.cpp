#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#define MAXN 200000;
#define Amari 1000000007;
#define p pair <int,int>
using namespace std;
int main(int argc,char const* argv[])
{
  int n;
  cin >> n;
  vector<long long> a(n,0);
  long long sum=0;
  long long min=LONG_MAX;
  long long temp=0;
  for(int i=0;i<n;i++)
    {
      cin >> a[i];
      sum+=a[i];
    }
  for(int i=0;i<n-1;i++)
    {
      temp+=a[i];
      if((abs(sum-2*temp))<min) min=abs(sum-2*temp);
    }
  cout << min << endl;
  return 0;
}
