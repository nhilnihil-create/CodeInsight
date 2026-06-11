#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,ans=0;
  cin>>N;
  unordered_map<int,int> M;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(M[a]==0){M[a]=1;ans++;}
    else if(M[a]==1){M[a]=0;ans--;}
  }
  cout<<ans<<endl;
}