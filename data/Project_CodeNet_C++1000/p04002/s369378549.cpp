/// kAAzuki Hoshino
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}

int h,w,n,ans[10];
vector<pair<int,int>> points,black;

signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

  cin >> h >> w >> n;
  for(int i=1;i<=n;i++){
    int x,y;
    cin >> x >> y;
    black.pb({x,y});
    for(int dx=-2;dx<=0;dx++){
      for(int dy=-2;dy<=0;dy++){
        if( x+dx>=1 && x+dx+2<=h && y+dy>=1 && y+dy+2<=w   )
        points.pb({ x+dx, y+dy });
      }
    }
  }
  sort(all(points));
  sort(all(black));
  points.erase(unique(all(points)), points.end());

  for(auto t:points){
    int x = t.fs;
    int y = t.sc;
    int cnt = 0;
    for(int dx=0;dx<=2;dx++){
      for(int dy=0;dy<=2;dy++){
        if(binary_search( all(black) , make_pair( x+dx, y+dy ) ))cnt++;
      }
    }
    ans[cnt]++;
  }

  ans[0] = (h-2)*(w-2) - points.size();

  for(int i=0;i<=9;i++){
    cout << ans[i] << endl;
  }


return 0;
}
///....
