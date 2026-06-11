#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,x;
  cin>>n>>x;
  if(n==2&&x==2){
    cout<<"Yes"<<endl;
    cout<<1<<endl;
    cout<<2<<endl;
    cout<<3<<endl;
    return 0;
  }
  if(x==2){
    cout<<"Yes"<<endl;
    int a=0;
    for(int i=0;i<2*n-1;i++){
      if(i<n-2||i>n+1){
        cout<<a+5<<endl;
        a++;
      }
      if(i==n-2){
        cout<<3<<endl;
      }
      if(i==n-1){
        cout<<2<<endl;
      }
      if(i==n){
        cout<<1<<endl;
      }
      if(i==n+1){
        cout<<4<<endl;
      }
    }
    return 0;
  }
  if(x+1>2*n-1||x-2<1){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  int vec[2*n-1],vecb[2*n]={0},a=0;
  vec[n-2]=x-2;
  vec[n-1]=x;
  vec[n]=x+1;
  vec[n+1]=x-1;
  vecb[x-2]++;
  vecb[x]++;
  vecb[x+1]++;
  vecb[x-1]++;
  for(int i=0;i<2*n-1;i++){
    if(i<n-2||i>n+1){
      if(vecb[a+1]==0){
        vec[i]=a+1;
        vecb[a+1]++;
        a++;
        continue;
      }
      while(vecb[a+1]>0){
        a++;
      }
      vecb[a+1]++;
      vec[i]=a+1;
    }
  }
  for(int i=0;i<2*n-1;i++){
    cout<<vec[i]<<endl;
  }
}