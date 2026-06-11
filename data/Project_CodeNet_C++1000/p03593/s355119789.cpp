#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int H,W;
  cin>>H>>W;
  vector<string> S(H);
  rep(i,H) cin>>S[i];
  VI X(26);
  rep(i,H) rep(j,W) X[S[i][j]-'a']++;
  sort(all(X));
  int ans=1;
  int tmp;
  rep(i,(H/2)*(W/2)){
    if(X[25]<4) ans=0;
    else X[25]-=4;
    sort(all(X));
  }
  rep(i,(H/2)*(W%2)+(H%2)*(W/2)){
    if(X[25]<2) ans=0;
    else X[25]-=2;
    sort(all(X));
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}