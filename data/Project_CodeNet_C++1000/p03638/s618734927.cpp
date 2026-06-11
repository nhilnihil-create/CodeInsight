#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int H,W,N;
  cin>>H>>W>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  int h=0;
  int w=0;
  int color=0;
  int flow=0;
  vector<vector<int>> c(H,vector<int>(W));
  while(h<H){
    if(flow==0){
      while(w<W){
        while(a.at(color)>0){
          c.at(h).at(w)=color+1;
          a.at(color)--;
          w++;
          if(w==W){
            flow=1;
            h++;
            break;
          }
        }
        if(a.at(color)==0){
          color++;
        }
      }
      w--;
    }else{
      while(w>=0){
        while(a.at(color)>0){
          c.at(h).at(w)=color+1;
          a.at(color)--;
          w--;
          if(w==-1){
            flow=0;
            h++;
            break;
          }
        }
        if(a.at(color)==0){
          color++;
        }
      }
      w++;
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<c.at(i).at(j)<<" ";
    }
    cout<<endl;
  }
}
