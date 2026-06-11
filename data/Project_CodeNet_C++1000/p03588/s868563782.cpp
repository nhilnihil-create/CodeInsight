#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
   int n;
   cin >> n;
   pair<int,int> fm=make_pair(0,0);
   rep(i,n)
   {
      int a,b;
      cin >> a >> b;
      pair<int ,int> p;
      p = make_pair(a,b);
      if(p.first>fm.first)fm = p;
   }
   cout<<fm.first+fm.second<<endl;
   return 0;
}