#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <math.h>
#include <array>
#include <list>
#include <map>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
set <int> st;
int h,w,n,a,b;
vector<ll> black(10);
map<pll,ll> m;
int main(int argc,char const* argv[])
{
  cin >> h >> w >> n;
  for(int i=0;i<n;i++)
    {
      cin >> a >> b;
      for(int j=b-2;j<=b;j++)
	{
	  for(int k=a-2;k<=a;k++)
	    {
	      if(1<=k && k<=h-2 && 1<=j && j<=w-2) m[pll(k,j)]++;
	    }
	}
    }
  for(auto it=m.begin();it !=m.end();it++)
    {
      black[it->second]++;
    }
  black[0]=(ll)(h-2)*(w-2)-m.size();
  for(int i=0;i<=9;i++)
    {
      cout << black[i] << endl;
    }
    return 0;
}
