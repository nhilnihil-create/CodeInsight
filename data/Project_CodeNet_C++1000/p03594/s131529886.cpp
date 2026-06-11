#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int h,w,d;
  cin>>h>>w>>d;

  char ans[h+1][w+1]={};
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          int x=(i+j)%(2*d);
          int y=(i-j)%(2*d);
          y=(y+2*d)%(2*d);
          if(x<d){
              if(y<d) ans[i][j]='R';
              else ans[i][j]='B';
          }else{
              if(y<d) ans[i][j]='Y';
              else ans[i][j]='G';
          }
      }
  }

  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          cout<<ans[i][j];
      }
      cout<<endl;
  }

  return 0;
}
