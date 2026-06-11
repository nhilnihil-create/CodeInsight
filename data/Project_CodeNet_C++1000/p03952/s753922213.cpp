#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";}
template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";}
template<typename T> void caut(T a){cout<<"("<<a<<") ";}

int main() {
  int n,x; cin>>n>>x;
  if (x==1||x==2*n-1) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  if (n==2) {
    // x==2
    cout<<"1 2 3"<<endl;
    return 0;
  }
  int an[2*n-1]={};
  bool use[2*n-1]; fill(use,use+2*n-1,false);
  if (x==2) {
    an[n]=4;
    an[n-1]=1;
    an[n-2]=2;
    an[n-3]=3;
    for(int i=0;i<4;i++) use[i]=true;
  } else {
    an[n]=x-2;
    an[n-1]=x+1;
    an[n-2]=x;
    an[n-3]=x-1;
    for(int i=0;i<4;i++) use[x+i-3]=true;
  }
  for(int i=0,j=0;i<2*n-1;i++) {
    if (an[i]>0) continue;
    while(use[j]) j++;
    an[i]=j+1;
    use[j]=true;
  }
  for(int i=0;i<2*n-1;i++) {
    cout<<an[i]<<endl;
  }
}