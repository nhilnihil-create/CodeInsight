#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <array>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int H,W;
string board[405];
int memo[405][405][2];
bool used[405][405];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main(int argc,char const* argv[])
{
  int n;
  cin >> n;
  int tmp=0;
  int maxpoint=0;
  for(int i=1;i<=n;i++)
    {
      tmp+=i;
      maxpoint=i;
      if(tmp>=n)break;
    }
  //cout << tmp << ' ' << maxpoint << endl;
  for(int i=1;i<=maxpoint;i++)
    {
      if(i==tmp-n) continue;
      cout << i << endl;
    }
  return 0;
}
