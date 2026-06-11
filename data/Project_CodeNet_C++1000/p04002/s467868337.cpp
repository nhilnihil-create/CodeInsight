#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

vector<int> dz = {-1,0,1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  ll h,w,n;
  cin>>h>>w>>n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n) cin>>a[i]>>b[i];
  map<int,map<int,int>> mp;
  rep(i,n) {
    mp[a[i]][b[i]]=1;
  }
  set<pair<int,int>> ps;
  vector<ll> c(10);
  ll s=0;
  rep(i,n) {
    rep(j,3) {
      rep(k,3) {
        int aa=a[i]+dz[j];
        int bb=b[i]+dz[k];
        if(2<=aa&&aa<=h-1&&2<=bb&&bb<=w-1) 
          ps.insert(make_pair(aa,bb));
      }
    }
  }
  c[0]=static_cast<ll>(h-2)*static_cast<ll>(w-2)-ps.size();
  for(auto& p : ps) {
    int aa,bb;
    tie(aa,bb)=p;
    int t=0;
    rep(i,3) {
      rep(j,3) {
        int aaa=aa+dz[i];
        int bbb=bb+dz[j];
        if(aaa<=0||h<aaa||bbb<=0||w<bbb) {
          goto F;
        }
        t+=mp[aaa][bbb];
      }
    }
    c[t]++;
    F:;
  }
  rep(i,10) {
    cout << c[i]<<endl;
  }
  return 0;
}
