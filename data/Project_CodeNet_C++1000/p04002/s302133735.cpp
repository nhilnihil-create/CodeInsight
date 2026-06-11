#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(v) for (int i = 0; i < v.size(); i++)
#define SORT(i,v) sort(v.begin(), v.end())
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = INF + 7;

ull ans[10];
map<pair<int, int>, int> mp;

int main()
{
  int h, w, n;
  cin>>h>>w>>n;
  ans[0] = (ull)(h-2) * (w-2);

  REP(i,n) {
    int a, b;
    cin>>a>>b;
    FOR(dx,-1,2) {
      FOR(dy,-1,2) {
        if (a+dx<2 || a+dx>h-1 || b+dy<2 || b+dy>w-1)
          continue;

        //cout<<a<<" "<<b<<" "<<a+dx<<" "<<b+dy<<endl;
        pair<int, int> tmpp = {a+dx,b+dy};//make_pair(a+dx,b+dy);
        //ここの入力形式はどちらでも問題がないようです
        if (mp.find(tmpp) == mp.end()) {
          mp[tmpp] = 1;
          ans[0]--;
        } else {
          mp[tmpp]++;
        }
      }
    }
  }

  for (auto itr : mp) {
    //cout<<itr.first.first<<" "<<itr.first.second<<" "<<itr.second<<endl;
    ans[itr.second]++;
  }

  REP(i,10) {
    cout<<ans[i]<<endl;
  }

  return 0;
}
