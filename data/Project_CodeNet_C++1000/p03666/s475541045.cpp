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
#include <set>
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
typedef vector<int> vi;
ll N;
ll A,B,C,D;
int main(int argc,char const* argv[])
{
  cin >> N >> A >> B >> C >> D;
  for(ll m=0;m<N;m++)
    {
      if(((B-A)>=C*(N-1-m)-D*m) && ((B-A)<=((N-1-m)*D-C*m)))
	{
	  cout << "YES" << endl;
	  return 0;
	}
    }
  cout << "NO" << endl;
  return 0;
}
