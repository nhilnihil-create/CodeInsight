#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "


const int N = 5e3+2;

bitset<N> bl[N], br[N];
int n, k;
void print(bitset<N> bit)
{
  cerr << "bit contains";
  for (int i = 0; i <= k; ++i)
    if (bit[i] == 1)
      cerr << " " << i;
  cerr << endl;
}
int main()
{

  while (~scanf("%d %d", &n, &k))
    {
      vector<int> v;
      for (int i = 0; i < n; ++i)
	{
	  int x;
	  scanf("%d", &x);
	  if (x < k) v.pb(x);
	}
      bl[0].reset();
      bl[0][0] = 1;
      for (int i = 0; i < v.size(); ++i)
	{
	  bl[i+1] = bl[i] | (bl[i] << v[i]);
	}
      br[v.size()+1].reset();
      br[v.size()+1][0] = 1;
      for (int i = int(v.size())-1; i >= 0; --i)
	{
	  br[i+1] = br[i+2] | (br[i+2] << v[i]);
	}
      int ans = v.size();
      for (int i = 0; i < v.size(); ++i)
	{
	  int need = k - v[i];
	  int r = k;
	  //	  cerr << "deal with " << v[i] << " need " << need << endl;
	  //	  print(bl[i]);
	  //	  print(br[i+2]);
	  for (int l = 0; l < k; ++l)
	    if (bl[i][l] == 1)
	      {
		while (r >= 0 && (r+l >= k || br[i+2][r] == 0)) --r;
		if (r == -1)
		  {
		    //		    cerr << "break " << l << " " << r << endl;
		  }
		else if (l + r >= need)
		  {
		    //		    cerr << "elimated by " << l << " and " << r << endl;
		    --ans; break;
		  }
		//		cerr << l << " match with " << r << endl;
	      }
	}
      printf("%d\n", ans);
    }
}
