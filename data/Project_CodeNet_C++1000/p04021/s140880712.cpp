#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i].first;
    A[i].second=i;
  }
  sort(A.begin(),A.end());
  int cnt=0;
  for(int i=0;i<N;i++)
    if((A[i].second-i)%2!=0)cnt++;
  cout<<cnt/2<<endl;
}