#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  int N;
  cin>>N;
  int a[N];
  for(int i=0;i<N;++i) cin>>a[i];
  
  int cl[H*W];
  int cnt=0;
  for(int i=0;i<N;++i){
    for(int j=cnt;j<cnt+a[i];++j){
      cl[j]=i+1;
    }
    cnt += a[i];
  }


  cnt=0;
  for(int i=0;i<H;++i){
    if(i%2==0) cnt=0;
    else cnt=1;
    for(int j=0;j<W;++j){
      if(cnt==0){
        cout<<cl[j+i*W]<<" ";
        if(j==W-1) cout<<" "<<endl;
      }
      else{
        cout<<cl[W-1-j+i*W]<<" ";
        if(j==W-1) cout<<" "<<endl;
      }
    }
  }

}
