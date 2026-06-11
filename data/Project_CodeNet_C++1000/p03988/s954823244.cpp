#include<iostream>
using namespace std;
int main(){
  int n,i,a,c[111],ma=0,mi=111;
cin>>n;
  for(i=0;i<=n;i++)
    c[i]=0;
  for(i=0;i<n;i++){
    cin>>a;
    c[a]++;
    ma=max(ma,a);
    mi=min(mi,a);
  }
  if(ma%2==0){
    if(mi*2!=ma||c[mi]!=1){
      cout<<"Impossible"<<endl;
      return 0;
    }
    for(i=mi+1;i<=ma;i++){
      if(c[i]<2){
        cout<<"Impossible"<<endl;
      return 0;
      }
    }
    cout<<"Possible"<<endl;
  }
  else{
    if(mi*2!=ma+1||c[mi]!=2){
      cout<<"Impossible"<<endl;
      return 0;
    }
    for(i=mi;i<=ma;i++){
      if(c[i]<2){
        cout<<"Impossible"<<endl;
      return 0;
      }
    }
    cout<<"Possible"<<endl;
  }
}
