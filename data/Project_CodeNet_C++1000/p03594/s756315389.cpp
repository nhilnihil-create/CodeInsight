#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int h,w,d;
  cin >> h >> w >> d;
  if(d%2){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if((i+j)%2){
          cout << "R" << flush;
        }else{
          cout << "B" << flush;
        }
      }
      cout << endl;
    }
  }else{
    char C[4]={'R','G','B','Y'};
    vector<char> field(w);
    bool zouka=true;
    int haba=0;
    char tmp;
    for(int i=0;i<h;i++){
      for(int j=0;j<=(w+d/2-1)/(d/2);j++){
        if(j%2){
          for(int k=-haba;k<haba;k++){
            // cout << j+k << endl;
            if(0<=j*(d/2)+k&&j*(d/2)+k<w) field[j*(d/2)+k]=C[j%4];
          }
        }else{
          for(int k=haba-d/2;k<d/2-haba;k++){
            // cout << j+k << endl;
            if(0<=j*(d/2)+k&&j*(d/2)+k<w) field[j*(d/2)+k]=C[j%4];
          }
        }
      }
      if(zouka){
        haba++;
        if(haba==d/2){
          zouka=false;
          tmp=C[2];
          C[2]=C[0];
          C[0]=tmp;
        }
      }else{
        haba--;
        if(haba==0){
          zouka=true;
          tmp=C[1];
          C[1]=C[3];
          C[3]=tmp;
        }
      }
      for(int j=0;j<w;j++){
        cout << field[j];
      }
      cout << endl;
    }
  }
  return 0;
}
