#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int W,H;
  cin>>W>>H;
  vector<pair<ll,bool>> v;
  for(int i=0;i<W;i++){
    ll p;
    cin>>p;
    v.push_back(make_pair(p,true));
  }
  for(int i=0;i<H;i++){
    ll q;
    cin>>q;
    v.push_back(make_pair(q,false));
  }

  sort(v.begin(),v.end());

  ll ans=0;
  ll w=W+1,h=H+1;
  for(int i=0;i<v.size();i++){
    if(v[i].second==true){
      ans=ans+h*v[i].first;
      w--;
    }else{
      ans=ans+w*v[i].first;
      h--;
    }
  }

  cout<<ans<<endl;

  return 0;
}
