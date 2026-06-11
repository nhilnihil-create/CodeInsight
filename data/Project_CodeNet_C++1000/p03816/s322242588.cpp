#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans;
  bool aa=true;
  cin >> n;
  ans=n;
  vector<long> a(n);
  map<long,long> aaa;
  vector<long> b;

  for(long i=0;i<n;i++) cin >> a[i];
  
  for(long i=0;i<n;i++) aaa[a[i]]++;

  for(auto itr=aaa.begin();itr!=aaa.end();itr++) {
    if((*itr).second>=3) ans-=(*itr).second,aaa[(*itr).first]=((*itr).second+1)%2+1,ans+=aaa[(*itr).first];
    if((*itr).second==2) {
      aa=!aa;
      if(aa) {
        ans-=2;
      }
    }
  }

  if(!aa) {
    ans-=2;
  }
  cout << ans << endl;
}