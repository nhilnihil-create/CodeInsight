#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int N, ans = 0;
  vector<int> A;

  cin>>N;

  A.resize(N);

  for(int i = 0;i < N; i++){
    cin>>A[i];
  }

  for(int i = 0, x = 1;i < N; i++){

    if(A[i] == x){
      ans += A[i]/x - 1;
        x++;
    } else {
      ans += A[i]/x;
      if(A[i]%x == 0) ans--;
      if(!i)x++;
    }
    //cout<<"i = "<<i<<" A = "<<A[i]<<" ans = "<<ans<<" x = "<<x<<endl;
  }

  cout<<ans<<endl;
  return 0;
}
