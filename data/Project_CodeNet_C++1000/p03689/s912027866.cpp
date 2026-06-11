#include <bits/stdc++.h>

using namespace std;

int H,W,h,w;

int main() {
  
  cin>>H>>W>>h>>w;

  int P,Q;

  if(H%h!=0){
    cout<<"Yes"<<endl;
    int N=H/h; 
    int plus=100000;
    int minus=-plus/(h-1)-1;

    int c=h-1;

  for(int j=0; j<H; j++){

  if(c==h-1){
      for(int i=0; i<W; i++){
          printf("%d ", plus);
      }
        c=0; 
  }
  else{
      for(int i=0; i<W; i++){
      printf("%d ", minus);
      }
      c++;
  }
  cout<<endl;
  }

  return 0;

  }

  else if(W%w!=0){

    cout<<"Yes"<<endl;
    int N=W/w; 
    int plus=100000;
    int minus=-plus/(w-1)-1;

  for(int j=0; j<H; j++){

    int c=w-1;

    for(int i=0; i<W; i++){
          if(c==w-1){
            printf("%d ", plus);
            c=0;
          }
          else{
            printf("%d ", minus);
            c++;
          }

      }
       cout<<endl;
  }

  return 0;
  }
  else{
    cout<<"No"<<endl;
  }

}