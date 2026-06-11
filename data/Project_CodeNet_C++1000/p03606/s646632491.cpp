#include <bits/stdc++.h>
using namespace std;

int main(){
   int N;
   cin>>N;
   int ans = 0;

  for(int i=0;i<N;i++){
    int X;
   int A,B;
   cin>>A>>B;
   //cout<<A<<B<<endl;
   X = B-A+1;
   ans+=X;
  }
  cout<<ans<<endl;
   

}
