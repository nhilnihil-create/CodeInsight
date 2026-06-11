#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int main(){
  int a,c,d,e;
  vector<pair<int,int> > b;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>c>>d;
    b.push_back(make_pair(c,d));
  }
  sort(b.begin(),b.end(),greater<pair<int,int> >());
  e=b[0].fi+b[0].se;
  cout<<e<<"\n";
}