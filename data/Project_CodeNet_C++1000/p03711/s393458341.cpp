#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>>X(3);
  vector<int>a={1,3,5,7,8,10,12};
  vector<int>b={4,6,9,11};
  vector<int>c={2};
  X[0]=a;
  X[1]=b;
  X[2]=c;
  int x,y;
  cin>>x>>y;
  for(int i=0;i<3;i++){
    bool xx=false,yy=false;
    for(auto it:X[i]){
      if(x==it)xx=true;
      if(y==it)yy=true;
    }
    if(xx&&yy){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;

  return 0;
}
