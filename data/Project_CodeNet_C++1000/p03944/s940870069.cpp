#include <bits/stdc++.h>
using namespace std;

int main(){
  int w,h,n;
  cin >> w >> h >> n;
  vector<vector<int>>hyo(n,vector<int>(3));
  for(int i=0;i<n;i++)
    cin >> hyo.at(i).at(0) >> hyo.at(i).at(1) >> hyo.at(i).at(2);
  int lx=0,ly=0,rx=w,ry=h;
  for(int i=0;i<n;i++){
    if(hyo.at(i).at(2)==1){
     if(hyo.at(i).at(0)>lx)
       lx=hyo.at(i).at(0);
    }else if(hyo.at(i).at(2)==2){
     if(hyo.at(i).at(0)<rx)
       rx=hyo.at(i).at(0);
    }else if(hyo.at(i).at(2)==3){
     if(hyo.at(i).at(1)>ly)
       ly=hyo.at(i).at(1);
    }else if(hyo.at(i).at(2)==4){
     if(hyo.at(i).at(1)<ry)
       ry=hyo.at(i).at(1);
    }
  }
    if(rx-lx>0&&ry-ly>0)
      cout << (rx-lx)*(ry-ly) << endl;
    else
      cout << 0;
    exit(0);
}