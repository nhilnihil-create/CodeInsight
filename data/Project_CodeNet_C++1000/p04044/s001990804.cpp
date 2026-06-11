#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int n, l; cin >> n >> l;
   vector<string> v;
   for(int i =0; i < n; i++)
   {
      string s; cin >> s;
      v.push_back(s);
   }
   sort(all(v));
   for(auto s : v) cout << s;



	return 0;
}
