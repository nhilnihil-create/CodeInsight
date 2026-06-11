#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  int ans=(int)(S.size())*((int)(S.size())-1)/2+1;
  vector<int> A(26);
  for(char c:S){
    ans-=A[c-'a'];
    A[c-'a']++;
  }
  cout<<ans<<endl;
}