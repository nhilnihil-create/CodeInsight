#include<bits/stdc++.h>
using namespace std;
int main(){
 int N;cin>>N;
  int MAX;
  for (int i=1; i<=N; i*=2){
    if(i*2>N){
      MAX=i;
      break;
    }
  }
  cout<<MAX<<endl;
}
