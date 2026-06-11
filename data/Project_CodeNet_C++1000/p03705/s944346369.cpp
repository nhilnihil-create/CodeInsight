#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  cout<<max(0LL,(A+B*(N-1))-(A*(N-1)+B)+1)<<endl;
}