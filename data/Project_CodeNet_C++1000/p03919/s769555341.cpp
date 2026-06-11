#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
//#define int long long
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


signed main(){
  int h,w;cin>>h>>w;
  rep(j,h){
    rep(i,w){
      string s;cin>>s;
      if(s=="snuke")cout << (char)('A'+i) << j+1 << endl;
    }
  }
}