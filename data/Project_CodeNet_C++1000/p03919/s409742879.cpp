#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;
  string s[h][w];
  char ap[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      cin>>s[i][j];
    }
  }
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      if(s[i][j] == "snuke") {
        char let = toupper(ap[j]);
        cout << let << i + 1 << endl;
        return 0;
      }
    }
  }

  

  return 0;
}
