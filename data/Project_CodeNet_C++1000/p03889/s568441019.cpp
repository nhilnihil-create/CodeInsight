/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  string s,u;
  cin >> s;
  if(s.size()%2) {
    cout << "No" << endl;
    return 0;
  }
  u=s;
  reverse(s.begin(),s.end());
  for(int i=0; i<s.size(); i++) {
    if((s[i]=='p'&&u[i]!='q')||(s[i]!='q'&&u[i]=='p')) {
      cout << "No" << endl;
      return 0;
    }
    if((s[i]=='b'&&u[i]!='d')||(s[i]=='d'&&u[i]!='b')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}