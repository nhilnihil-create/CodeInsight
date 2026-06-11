#include<bits/stdc++.h>
using namespace std;

int main(){
  int W,H,N;
  cin >>W>>H>>N;
  int data[N][3];
  for(int i=0;i<N;i++){
    cin>>data[i][0]>>data[i][1]>>data[i][2];
  }
  vector<int> x(W);
  vector<int> y(H);
  for(int i=0;i<N;i++){
    if(data[i][2]==1){
      for(int j=0;j<data[i][0];j++){
        x[j]=1;
      }
    }
    if(data[i][2]==2){
      for(int j=data[i][0];j<W;j++){
        x[j]=1;
      }
    }
    if(data[i][2]==3){
      for(int j=0;j<data[i][1];j++){
        y[j]=1;
      }
    }
    if(data[i][2]==4){
      for(int j=data[i][1];j<H;j++){
        y[j]=1;
      }
    }
  }
  int sum_x=0;
  int sum_y=0;
  for(int a:x){
    if(a==0)sum_x++;
  }
  for(int a:y){
    if(a==0)sum_y++;
  }
  cout << sum_x*sum_y<<endl;
}
