#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

int main()
{
  int n;
  while (~scanf("%d", &n))
    {
      vector<int> v(n);
      map<int, int> ma;
      for (auto & e : v) scanf("%d", &e), ++ma[e];
      int diameter = ma.rbegin()->first;
      int mini = (diameter + 1) >> 1;
      bool ans = true;
      if (ma.begin()->first != mini || ma.size() != (diameter - mini + 1)) ans = false;
      else if ((diameter % 2 == 0) && ma[mini] != 1) ans = false;
      else if ((diameter % 2 == 1) && ma[mini] != 2) ans = false;
									    
      puts(ans?"Possible":"Impossible");
    }
}
