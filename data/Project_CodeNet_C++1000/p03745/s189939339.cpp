#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,k;
  cin>>N>>k;
  int bo=0,l=1;
  for(int i=1;i<N;i++){
    int j;
    cin>>j;
    if((j<k && bo==1)||(j>k && bo==-1)){
      l++;
      bo=0;
    }
    else{
      if(j<k)
        bo=-1;
      if(j>k)
        bo=1;
    }
    k=j;
  }
  cout<<l<<endl;
}