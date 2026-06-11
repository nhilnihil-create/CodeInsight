#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  int na=1;
  int ac=n+1;
  long long int mid=(ac+na)/2;
  while(na+1<ac){
    if(mid*(mid+1)/2>=n){
      ac=mid;
    }else{
      na=mid;
    }
    mid=(ac+na)/2;
  }
  
  int point=n;
  for(int i=ac;i>0;i--){
    if(i<=point){
      cout<<i<<endl;
      point-=i;
    }
  }
  return(0);
}
