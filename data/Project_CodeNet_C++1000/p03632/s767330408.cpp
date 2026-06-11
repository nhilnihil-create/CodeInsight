#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A,B,C,D;
  cin>>A>>B>>C>>D;
  if(B<=C||D<=A) {
    cout<<0<<endl;
    return 0;

  }
 vector<ll> vec(4);
 vec[0]=A;
 vec[1]=B;
 vec[2]=C;
 vec[3]=D;
 sort(all(vec));
 cout<<vec[2]-vec[1]<<endl;
}