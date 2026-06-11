#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << nl;
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
const int MAXN = 100005;
ll mod=1000000007;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  // cin>>t;
  while(t--){
      int n;
      cin>>n;
      ii p = {0,0};
      rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        if(mp(u,v) > p){
          p = mp(u,v);
        }
        //largest a[i] se smaller all values
      }
      cout<<(p.F + p.S)<<nl;
  }
  return 0;
}
