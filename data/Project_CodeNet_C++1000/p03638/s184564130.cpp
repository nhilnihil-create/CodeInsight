#include<iostream>
#include<vector>
using namespace std;

int main(){
  int H,W;cin>>H>>W;
  int N;cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++) cin>>a[i];
  vector<vector<int> > fields(H,vector<int>(W));
  int i=0,j=0;
  for(int k=0;k<N;k++){
    int h=0;
    while(true){
      if(h==a[k]) break;
      fields[i][j]=k+1;
      j++;
      if(j==W){
        i++;
        j=0;
      }
      h++;
    }
  }
  for(int i=0;i<H;i++){
    if(!(i&1)){
      for(auto it=fields[i].begin();it!=fields[i].end();it++){
        cout<<*it<<((it==fields[i].end()-1)?'\n':' ');
      }
    }else{
      for(auto it=fields[i].rbegin();it!=fields[i].rend();it++){
        cout<<*it<<((it==fields[i].rend()-1)?'\n':' ');
      }
    }
  }
  return 0;
}