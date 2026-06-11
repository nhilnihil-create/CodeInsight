#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>A(N);
  
  for(int j=0;j<N;j++){
  int x;
    cin>>x;
    int sum=0;
    for(int i=0; ;i++){
    if(x%2==0){
     x/=2; sum++;
    }else
      break;
      if(sum==2) break;
    }A.at(j)=sum;
  
 }int a1=0;
  int a2=0;
  for(int i=0;i<N;i++){
   if(A.at(i)==1)
     a1++;
    if(A.at(i)==2)
      a2++;
  }if(1<=a1){if(2*a2+a1<N)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;}
  else{
  if(2*a2+1<N)
    cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
    
  return 0;
}