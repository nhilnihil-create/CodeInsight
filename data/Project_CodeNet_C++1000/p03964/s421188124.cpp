#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
  vector<long>t(n),a(n);
  rep(i,n){
    cin>>t.at(i)>>a.at(i);
  }
  long ans=t.at(0)+a.at(0);
  rep2(i,1,n){
    long ch=(ans/(t.at(i-1)+a.at(i-1))*a.at(i-1)-1)/a.at(i)+1LL;
    if(ch<(ans/(t.at(i-1)+a.at(i-1))*t.at(i-1)-1LL)/t.at(i)+1LL){
      ch=(ans/(t.at(i-1)+a.at(i-1))*t.at(i-1)-1LL)/t.at(i)+1LL;
    }
    if(ch<((ans-1LL)/(t.at(i)+a.at(i))+1LL)){
      ch=((ans-1LL)/(t.at(i)+a.at(i))+1LL);
    }
    ans=ch*(t.at(i)+a.at(i));
  }
  
    cout<<ans<<endl;
  
}



