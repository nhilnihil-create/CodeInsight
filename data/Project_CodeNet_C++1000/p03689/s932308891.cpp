#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int h,w,x,y;
  cin>>h>>w>>x>>y;
  if(h%x==0&&w%y==0){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  if(w%y!=0){
    int vec[w];
    int big=10000*(y-1)-1,small=-10000;
    for(int i=0;i<w;i++){
      if(i%y==0){
        vec[i]=big;
      }
      else{
        vec[i]=small;
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cout<<vec[j]<<" ";
      }
      cout<<endl;
    }
    return 0;
  }
  int vec[h];
  int big=10000*(x-1)-1,small=-10000;
  for(int i=0;i<h;i++){
    if(i%x==0){
      vec[i]=big;
    }
    else{
      vec[i]=small;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<vec[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}