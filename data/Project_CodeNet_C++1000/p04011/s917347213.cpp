#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K,X,Y; cin>>N>>K>>X>>Y;
  cout<<min(K,N)*X+max(0,N-K)*Y<<endl;
}
