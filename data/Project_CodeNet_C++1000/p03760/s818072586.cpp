#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string O,E;
  cin>>O>>E;
  rep(i,O.size()){
    cout<<O[i];
    if(i<E.size())cout<<E[i];
  }
  cout<<endl;
}