#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;

int main() {
  string s;
  cin>>s;
  for(int i:irange(0,(int)s.size(),2)){
    cout<<s[i];
  }
  cout<<'\n';
  return(0);
}