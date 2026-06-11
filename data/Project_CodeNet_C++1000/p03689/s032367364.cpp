#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000000;
signed main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  if(H%h==0 && W%w==0){
    puts("No");
    return 0;
  }
  puts("Yes");
  if(W%w!=0){
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(j%w==0)cout<<INF-1;
        else if(j%w==w-1)cout<<-INF;
        else cout<<0;
        cout<<(j==W-1?'\n':' ');
      }
    }
  }else{
    for(int i=0;i<H;i++){
      int n;
      if(i%h==0)n=INF-1;
      else if(i%h==h-1)n=-INF;
      else n=0;
      for(int j=0;j<W;j++)cout<<n<<(j==W-1?'\n':' ');
    }
  }
}