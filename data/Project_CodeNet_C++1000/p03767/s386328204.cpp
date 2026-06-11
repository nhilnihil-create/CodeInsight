#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;vector<long long>V(N*3);
  for(int X=0;X<N*3;X++)cin>>V[X];
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  long long K=0,M=0;
  for(int X=0;X<N*3;X++){
    if(X%2==1){
      K+=V[X];M++;
    }
    if(M==N)break;
  }
  cout<<K<<endl;
}