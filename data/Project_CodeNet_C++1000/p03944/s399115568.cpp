#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll W,H,n;
  ll area;
  cin>>W>>H>>n;
  area=W*H;
  
  ll x,y,a;
  ll mx[4];
  for(int i=0;i<4;i++){
    mx[i]=-1;
  }
  for(int i=0;i<n;i++){
    cin>>x>>y>>a;
    if(a==1){
      if(x>mx[a-1]||mx[a-1]==-1){
        mx[a-1]=x;
      }
    }
    if(a==2){
      if(x<mx[a-1]||mx[a-1]==-1){
        mx[a-1]=x;
      }
    }
    if(a==3){
      if(y>mx[a-1]||mx[a-1]==-1){
        mx[a-1]=y;
      }
    }
    if(a==4){
      if(y<mx[a-1]||mx[a-1]==-1){
        mx[a-1]=y;
      }
    }
  }
  
  if(mx[0]>mx[1]&&mx[0]!=-1&&mx[1]!=-1){
    area=0;
  }else{
    if(mx[2]>mx[3]&&mx[0]!=-1&&mx[1]!=-1){
      area=0; 
    }else{
      for(int i=0;i<4;i++){
          if(mx[i]==-1){
            mx[i]=0;
          }
      }
      area=(W-(mx[0]+(mx[1]==0?0:W-mx[1])))*(H-(mx[2]+(mx[3]==0?0:H-mx[3])));
    }
  }
  cout<<area<<endl;
  return 0;
}