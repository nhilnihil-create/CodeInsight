#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b,c;
  cin>>a>>b>>c;
  int asize,bsize;
  asize=a.size();
  bsize=b.size();
  if(a.at(asize-1)==b.at(0)&&b.at(bsize-1)==c.at(0)){
    cout <<"YES"<<endl;
    return 0;
  }
  else cout <<"NO"<<endl;
}
