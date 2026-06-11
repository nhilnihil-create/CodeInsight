#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w,n,r,c,a,b;
  cin >>h>>w>>n;
  map<pair<ll,ll>,ll> mp;
  set<pair<ll,ll> > index;
  for (int i=0;i<n;i++) {
    cin>>r>>c;
    r--;c--;
    for (ll dy=-1;dy<=1;dy++) {
      for (ll dx=-1;dx<=1;dx++) {
        a=r+dy;b=c+dx;
        if (a<=0||h-1<=a||b<=0||w-1<=b)continue;
        mp[make_pair(a,b)]++;
        index.insert(make_pair(a,b));
      }
    }
  }
  vector<ll> v(10,0);
  v[0]=(h-2)*(w-2);
  for (set<pair<ll,ll> > ::iterator itr=index.begin();itr!=index.end();itr++){
    v[mp[*itr]]++;
    v[0]--;
  }
  for (int i=0;i<10;i++)cout<<v[i]<<endl;
  return 0;
}
