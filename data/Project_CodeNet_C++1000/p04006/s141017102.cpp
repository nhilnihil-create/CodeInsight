#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  vector<int> m(n);
  int64_t mi=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    m.at(i)=a.at(i);
    mi+=m.at(i);
  }
  for(int i=1;i<n;i++){
    int64_t s=(int64_t)x*i;
    for(int j=0;j<n;j++){
      m.at(j)=min(m.at(j),a.at((j-i+n)%n));
      s+=m.at(j);
    }
    mi=min(s,mi);
  }
  cout<<mi<<endl;
}