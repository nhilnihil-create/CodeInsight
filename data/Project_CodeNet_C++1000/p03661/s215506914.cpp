#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<long long>B(N);
  for(int i=0;i<N;i++){cin>>A[i];B[i]=A[i]+(i!=0? B[i-1]:0);}
  long long ans=100000000000000;
  for(int i=0;i<N-1;i++)ans=min(ans,abs(B[i]*2-B[N-1]));
  cout<<ans<<endl;
}