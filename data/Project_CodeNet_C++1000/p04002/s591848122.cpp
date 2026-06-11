/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int main(){
  map<P, int> mp;
  int h, w, n;cin>>h>>w>>n;
  rep(i, n){
    int a, b;cin>>a>>b;a--;b--;
    repb(i, -1, 2){
      repb(j, -1, 2){
        if(a+i>=1&&a+i<h-1&&b+j>=1&&b+j<w-1)mp[P(a+i, b+j)]++;
      }
    }
  }
  vector<int> cnt(10, 0);
  ll sum=ll(h-2)*(w-2);
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    cnt[itr->second]++;
    sum--;
  }
  cout<<sum<<endl;
  repb(i, 1, 10){
    cout<<cnt[i]<<endl;
  }
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
