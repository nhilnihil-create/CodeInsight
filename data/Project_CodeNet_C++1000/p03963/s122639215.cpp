#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 int64_t N,K;
 cin>>N>>K;
 int64_t ans=1;
 for(int i=0;i<N-1;i++){
     ans*=(K-1);
 }
 cout<<K*ans<<endl;
 return 0;}