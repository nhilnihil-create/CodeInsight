#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define	s second
#define	int long long
using namespace	std;
signed main(){

  int w,h,r=0,t;
  vector <pair<int,int> > a;
  cin>>w>>h;
  for(int i=0;i<w&&cin>>t;i++) a.push_back(make_pair(t,0));
  for(int i=0;i<h&&cin>>t;i++) a.push_back(make_pair(t,1));
  sort(a.begin(),a.end());
  w++,h++;
  for(int i=0;i<(int)a.size();i++){
    if(a[i].s==0){
      r+=h*a[i].f;
      w--;
    }else {
      r+=w*a[i].f;
      h--;
    }
  }
  cout<<r<<endl;
  return 0;
}

