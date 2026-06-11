#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
  int n,m;
  cin >> n >> m;
  VI a(m);
  VI b(m);
  rep(i,m){
    cin >> a.at(i) >> b.at(i);
  }
  map<int,int> cntr;
  rep(i,m){
    if(a.at(i)==1){
      if(cntr.count(b.at(i))){
        cntr.at(b.at(i))++;
      }
      else{
        cntr[b.at(i)]=1;
      }
    }
    else if(b.at(i)==n){
      if(cntr.count(a.at(i))){
        cntr.at(a.at(i))++;
      }
      else{
        cntr[a.at(i)]=1;
      }
    }
  }
    bool x=false;
    for(auto p:cntr){
      int k=p.first;
      int v=p.second;
      if(v>=2){
        x=true;
        break;
      }
    }
    if(x)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE"  << endl;
  }
