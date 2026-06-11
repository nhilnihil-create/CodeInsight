#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <math.h>
#include <array>
#include <list>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> p;
typedef vector<int> vi;
typedef vector<ll> vll;
vll a(100005);
int n,t;
ll profit=0;
ll minval=INF+1;
int same=1;
string s;
int main(int argc,char const* argv[])
{
  cin >> n >> t;
  for(int i=0;i<n;i++)
    {
      cin >> a[i];
    }
  for(int i=0;i<n-1;i++)
    {
      if(a[i]<minval)
	{
	  minval=a[i];
	}
      if(a[i+1]-minval>profit) profit=a[i+1]-minval;
      else if(a[i+1]-minval==profit) same++;
    }
  cout << same << endl;
  return 0;
}
